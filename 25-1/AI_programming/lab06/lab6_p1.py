import torch
from torch import nn
from torch.utils.data import DataLoader
from torchvision import datasets, transforms
import random
import matplotlib.pyplot as plt
import numpy as np


class FashionMNISTTrainer:
	"""
    FashionMNISTTrainer
    Multi-layer perceptron for Fashion-MNIST classification.

    __init__: Initialize trainer by setting seed, device, dataset, dataloaders, and model.
    check_device: Print the device (CPU or GPU) being used for training.
    set_model: Define the MLP model, initialize weights, and set loss and optimizer.
    train: Train the model using the training dataset for a fixed number of epochs.
    eval: Evaluate a single image and return the predicted label.
    eval_all: Evaluate the model on the entire test set and print the accuracy.
    sample_test_image: Randomly sample and return a single test image and its true label.
    export_model: Save the model's state_dict to a file.
    import_model: Load the model's state_dict from a file.
    set_seed: Set random seed for reproducibility across torch and numpy.
	"""
	def __init__(self, seed=2025):
		"""
		initializes FashionMNISTTrainer
		seed is fixed at 2025
		
		input: none (self)
		output: FashionMNISTTrainer object
		"""
		self.set_seed(seed=seed)

		self.device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

		self.transform = transforms.Compose([
			transforms.ToTensor(),
		])

		# load dataset
		self.train_data = datasets.FashionMNIST(
			root='FashionMNIST_data/',
			train=True,
			transform=self.transform,
			download=True
		)
		self.test_data = datasets.FashionMNIST(
			root='FashionMNIST_data/',
			train=False,
			transform=self.transform,
			download=True
		)

		self.train_data_loader = DataLoader(
			dataset=self.train_data,
			batch_size=100,
			shuffle=True,	# Shuffle the order of dataset
			drop_last=True
		)

		# model used for training
		self.set_model()

	def check_device(self):
		"""
		check what device is used (cpu or gpu)
		input: none (self)
		output: none (printing )
		"""
		print(f"Running on {self.device}.")

	def set_model(self):
		"""
		Setting Neural Network architecture
			1. set network
			2. initialize weight (if needed)

		"""

		### write your code...
		# 1. set network
		# MLP Layer setting
		linear1 = nn.Linear(784, 1024, bias=True)
		bn1 = nn.BatchNorm1d(1024)

		linear2 = nn.Linear(1024, 512, bias=True)
		bn2 = nn.BatchNorm1d(512)

		linear4 = nn.Linear(512, 256, bias=True)
		bn4 = nn.BatchNorm1d(256)

		linear5 = nn.Linear(256, 128, bias=True)
		bn5 = nn.BatchNorm1d(128)

		linear3 = nn.Linear(128, 10, bias=True)
		
		# 2. initialize weight (if needed)
		# By using xavier uniform function
		nn.init.xavier_uniform_(linear1.weight)
		nn.init.xavier_uniform_(linear2.weight)
		nn.init.xavier_uniform_(linear4.weight)
		nn.init.xavier_uniform_(linear5.weight)
		nn.init.xavier_uniform_(linear3.weight)
		
		# 3. set activation function
		# By using ReLU function, only because we learned about it.
		act_func = nn.ReLU()
		
		# 4. set model
		self.model = nn.Sequential(
			linear1, act_func, bn1, nn.Dropout(0.3),
			linear2, act_func, bn2, nn.Dropout(0.3),
			linear4, act_func, bn4, nn.Dropout(0.3),
			linear5, act_func, bn5, nn.Dropout(0.3),
			linear3
		).to(self.device)

		# 5. set loss and optimizer
		self.criterion = nn.CrossEntropyLoss().to(self.device)
		self.optimizer = torch.optim.Adam(self.model.parameters(), lr=0.001)
	
	def train(self):
		"""
		Train the model for 30 epochs and print average loss for each epoch.
		we set 30 epochs by the assignment announcement
		"""

		# train your model here
		# you may print the loss of your model

		# if you are running this code on 'cuda', (check by calling check_device())
		# you have to pass your image to device by using '.to(self.device)'
		# the same applies to function eval(...):

		# set to train mode
		batch_num = len(self.train_data_loader)
		self.model.train()

		cost_log = []
		for epoch in range(30):
			avg_cost = 0

			for X, Y in self.train_data_loader:
				X = X.view(-1, 28*28).to(self.device)
				Y = Y.to(self.device)

				self.optimizer.zero_grad()
				guess = self.model(X)
				cost = self.criterion(guess, Y)
				cost.backward()
				self.optimizer.step()

				avg_cost += cost / batch_num

			cost_log.append(float(avg_cost))
			print(f"Epoch: {epoch+1:02d}, cost={avg_cost:.9f}")

	@torch.no_grad()
	def eval(self, image):
		"""
		Evaluate a single image and return the predicted label
		input:
			image: image will have size of 28 * 28
		output:
			the label predicted by this model
		"""
		# image will have size of 28 * 28
		# you should return the label predicted by your model
		# this function only predicts the label of a single image

		# set model to eval mode
		self.model.eval()
		image = image.to(self.device)
		image = image.view(-1, 28*28)
		outputs = self.model(image)
		predicted_label = torch.argmax(outputs, 1).item()
		return predicted_label

	def eval_all(self):
		"""
		Evaluate the model on the entire test dataset and print accuracy
		
		no input required
		return None
		
		only prints Accuracy of the model
		"""
		acc_cnt, tot_cnt = 0, 0
		for image, label in self.test_data:
			pred = self.eval(image)
			acc_cnt += label == pred
			tot_cnt += 1

		print(f"Accuracy: {acc_cnt / tot_cnt * 100:.2f}%")

	def sample_test_image(self):
		"""Randomly sample a test image and return it along with its true label"""
		r = self.random.integers(low=0, high=len(self.test_data))
		return self.test_data[r]

	def export_model(self, file_name="lab6_p1.pth"):
		"""Export the model's state_dict to a file"""
		torch.save(self.model.state_dict(), file_name)

	def import_model(self, file_name="lab6_p1.pth"):
		"""Load the model's state_dict from a file."""
		state_dict = torch.load(file_name, map_location=torch.device(self.device))
		self.model.load_state_dict(state_dict)

	def set_seed(self, seed=2025):
		"""Set the random seed for reproducibility."""
		self.random = np.random.default_rng(seed)
		torch.manual_seed(seed)
		if torch.cuda.is_available():
			torch.cuda.manual_seed_all(seed)


if __name__ == "__main__":
	# 1. generate trainer
	trainer = FashionMNISTTrainer()

	# 2. run train
	trainer.train()

	# 3. evaluate on test set
	trainer.eval_all()

	# 4. pick a image and pass through the network
	image, label = trainer.sample_test_image()
	print(f'Label: {label}')
	print(f'Prediction: {trainer.eval(image)}')

	# 5. export model
	trainer.export_model()

	# 6. import model
	trainer.import_model()

	# 7. evaluate on test set
	# Note: ACCURACY MUST REMAIN THE SAME AS 3.
	trainer.eval_all()