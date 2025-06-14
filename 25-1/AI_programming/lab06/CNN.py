import torch
from torch import nn
from torch.utils.data import DataLoader
from torchvision import datasets, transforms
import random
import matplotlib.pyplot as plt # Used only in __main__ block for visualization
import numpy as np


class FashionMNISTTrainer:
    """
    FashionMNISTTrainer
    A Convolutional Neural Network (CNN) for Fashion-MNIST image classification.
    This class handles data loading, model definition, training, evaluation,
    and model saving/loading.

    Attributes:
        seed (int): Random seed for reproducibility.
        device (torch.device): Computation device (cuda or cpu).
        transform (torchvision.transforms.Compose): Image preprocessing pipeline.
        train_data (datasets.FashionMNIST): Fashion-MNIST training dataset.
        test_data (datasets.FashionMNIST): Fashion-MNIST test dataset.
        train_data_loader (DataLoader): DataLoader for training data.
        model (nn.Module): The defined CNN model.
        criterion (nn.Module): Loss function for training.
        optimizer (torch.optim.Optimizer): Optimizer for model parameters.
    """
    def __init__(self, seed=2025):
        """
        Initializes the FashionMNISTTrainer.
        Sets random seed, identifies the computation device,
        prepares data transformations, loads datasets, sets up data loaders,
        and defines the CNN model with its loss function and optimizer.

        Args:
            seed (int): The random seed to ensure reproducibility. Fixed at 2025 as per assignment.
        """
        self.set_seed(seed=seed)

        # Determine the computation device (GPU if available, otherwise CPU)
        self.device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

        # Define standard mean and standard deviation for Fashion-MNIST normalization
        # These values are common for this dataset
        mean = (0.2860,)
        std = (0.3530,)

        # Compose image transformations: convert to tensor and normalize pixel values
        self.transform = transforms.Compose([
            transforms.ToTensor(), # Converts PIL Image or numpy.ndarray to FloatTensor in [0.0, 1.0]
            transforms.Normalize(mean, std) # Normalizes tensor image with mean and std
        ])

        # Load the Fashion-MNIST training dataset
        # Data will be downloaded if not already present
        self.train_data = datasets.FashionMNIST(
            root='FashionMNIST_data/',
            train=True,
            transform=self.transform,
            download=True
        )
        # Load the Fashion-MNIST test dataset
        self.test_data = datasets.FashionMNIST(
            root='FashionMNIST_data/',
            train=False,
            transform=self.transform,
            download=True
        )

        # Create a DataLoader for the training data
        # Batch size is set to 128 for efficient training
        self.train_data_loader = DataLoader(
            dataset=self.train_data,
            batch_size=128,  # A common batch size for training
            shuffle=True,   # Shuffles data for each epoch to improve generalization
            drop_last=True  # Drops the last incomplete batch
        )

        # Initialize and set up the CNN model
        self.set_model()

    def check_device(self):
        """
        Prints the device (CPU or GPU) currently being used for training.

        Returns:
            None: This method prints to console and does not return any value.
        """
        print(f"Running on {self.device}.")

    def set_model(self):
        """
        Defines the Convolutional Neural Network (CNN) architecture.
        This method constructs the layers, initializes their weights,
        and sets up the loss function and optimizer.

        Returns:
            None: This method sets internal attributes and does not return any value.
        """

        # Define the CNN architecture as an inner class
        # This structure allows for clear definition of forward pass
        class CNN(nn.Module):
            """
            CNN architecture for Fashion-MNIST.
            Consists of two convolutional blocks followed by fully connected layers.
            """
            def __init__(self):
                """
                Initializes the CNN model's layers.
                Defines convolutional layers, pooling layers, batch normalization,
                and fully connected layers with dropout.
                """
                super(CNN, self).__init__()
                # First convolutional block
                self.layer1 = nn.Sequential(
                    # Input: 1 channel (grayscale), Output: 32 channels, Kernel: 3x3, Padding: 1
                    nn.Conv2d(in_channels=1, out_channels=32, kernel_size=3, padding=1),
                    nn.BatchNorm2d(32), # Batch normalization for stability
                    nn.ReLU(),          # Rectified Linear Unit activation
                    nn.MaxPool2d(kernel_size=2, stride=2) # 2x2 Max Pooling, halves dimension (28->14)
                )
                # Second convolutional block
                self.layer2 = nn.Sequential(
                    # Input: 32 channels, Output: 64 channels, Kernel: 3x3, Padding: 1
                    nn.Conv2d(in_channels=32, out_channels=64, kernel_size=3, padding=1),
                    nn.BatchNorm2d(64), # Batch normalization
                    nn.ReLU(),          # Activation
                    nn.MaxPool2d(kernel_size=2, stride=2) # 2x2 Max Pooling, halves dimension (14->7)
                )
                # Flatten layer to convert 2D feature maps to 1D vector for fully connected layers
                self.flatten = nn.Flatten()
                
                # First fully connected (dense) layer
                # Input features: 64 channels * 7 height * 7 width = 3136
                self.fc1 = nn.Sequential(
                    nn.Linear(64 * 7 * 7, 256), # Output 256 features
                    nn.BatchNorm1d(256), # Batch normalization for FC layer
                    nn.ReLU(),           # Activation
                    nn.Dropout(0.5)      # Dropout for regularization, prevents overfitting
                )
                # Output fully connected layer
                self.fc2 = nn.Linear(256, 10) # 10 output classes for Fashion-MNIST

                # Initialize weights using Kaiming Normal (He initialization)
                # This initialization is suitable for ReLU activation functions
                for m in self.modules():
                    if isinstance(m, nn.Conv2d):
                        nn.init.kaiming_normal_(m.weight, mode='fan_out', nonlinearity='relu')
                        if m.bias is not None:
                            nn.init.constant_(m.bias, 0)
                    elif isinstance(m, nn.Linear):
                        nn.init.kaiming_normal_(m.weight, mode='fan_out', nonlinearity='relu')
                        if m.bias is not None:
                            nn.init.constant_(m.bias, 0)
                    elif isinstance(m, (nn.BatchNorm2d, nn.BatchNorm1d)):
                        nn.init.constant_(m.weight, 1) # Weights to 1
                        nn.init.constant_(m.bias, 0)   # Biases to 0

            def forward(self, x):
                """
                Defines the forward pass of the CNN model.
                Processes input through convolutional layers, flattens,
                and then passes through fully connected layers.

                Args:
                    x (torch.Tensor): Input tensor (image batch) of shape (batch_size, 1, 28, 28).

                Returns:
                    torch.Tensor: Output tensor (logits) of shape (batch_size, 10).
                """
                out = self.layer1(x)
                out = self.layer2(out)
                out = self.flatten(out) # Flatten output before fully connected layers
                out = self.fc1(out)
                out = self.fc2(out)
                return out

        # Instantiate the CNN model and move it to the configured device
        self.model = CNN().to(self.device)

        # Set the loss function (CrossEntropyLoss is suitable for multi-class classification)
        self.criterion = nn.CrossEntropyLoss().to(self.device)
        # Set the optimizer (Adam is a robust choice)
        # Learning rate set to 0.001, and weight decay (L2 regularization) added
        self.optimizer = torch.optim.Adam(self.model.parameters(), lr=0.001, weight_decay=1e-5)

    def train(self):
        """
        Trains the CNN model using the training dataset for a specified number of epochs.
        Prints the average loss for each epoch.

        Returns:
            None: This method performs training and prints progress, without returning a value.
        """
        self.model.train() # Set the model to training mode
        
        cost_log = [] # List to store average cost per epoch
        num_epochs = 50 # Number of training epochs, can be adjusted for performance

        print(f"Starting training on {self.device} for {num_epochs} epochs...")
        for epoch in range(num_epochs):
            avg_cost = 0 # Initialize average cost for the current epoch
            # Iterate over batches from the training data loader
            for X, Y in self.train_data_loader:
                # Move input (X) and target (Y) tensors to the specified device
                X = X.to(self.device) # X is already (batch_size, 1, 28, 28) for CNN
                Y = Y.to(self.device)

                self.optimizer.zero_grad() # Zero the gradients before backpropagation
                guess = self.model(X)      # Perform forward pass to get predictions
                cost = self.criterion(guess, Y) # Calculate the loss
                cost.backward()            # Perform backpropagation
                self.optimizer.step()      # Update model parameters

                avg_cost += cost.item() # Accumulate loss, .item() gets scalar value

            # Calculate the average cost for the current epoch
            avg_cost /= len(self.train_data_loader) 
            cost_log.append(avg_cost) # Log the average cost
            print(f"Epoch: {epoch+1:02d}, cost={avg_cost:.9f}") # Print epoch progress
        print("Training finished.")

    @torch.no_grad() # Decorator to disable gradient calculations for efficiency
    def eval(self, image):
        """
        Evaluates a single input image and returns the predicted class label.
        This function is used for individual image prediction.

        Args:
            image (torch.Tensor): A single image tensor, expected to be of shape (C, H, W) e.g., (1, 28, 28).

        Returns:
            int: The predicted class label (0-9).
        """
        self.model.eval() # Set the model to evaluation mode
        
        # Add a batch dimension if the input image does not have one
        # Converts (C, H, W) to (1, C, H, W) as CNN expects a batch input
        if image.dim() == 3: 
            image = image.unsqueeze(0) 
        
        image = image.to(self.device) # Move image to the computation device
        
        outputs = self.model(image) # Get model predictions (logits)
        # Get the index of the maximum log-probability, which is the predicted label
        predicted_label = torch.argmax(outputs, 1).item()
        return predicted_label

    def eval_all(self):
        """
        Evaluates the model's performance on the entire test dataset.
        Calculates and prints the overall accuracy.

        Returns:
            None: This method prints the accuracy to console and does not return any value.
        """
        self.model.eval() # Set the model to evaluation mode
        correct_predictions = 0 # Counter for correctly classified samples
        total_samples = 0       # Counter for total samples evaluated

        with torch.no_grad(): # Disable gradient calculations for evaluation
            for image, label in self.test_data:
                # Add a batch dimension to the single image for model input
                # Converts (C, H, W) to (1, C, H, W)
                image_input = image.unsqueeze(0).to(self.device)
                
                outputs = self.model(image_input) # Get model predictions
                # Get the predicted class by finding the max value along dimension 1
                _, predicted = torch.max(outputs.data, 1)
                
                total_samples += 1 # Increment total samples
                # Increment correct predictions if predicted label matches true label
                correct_predictions += (predicted == label.to(self.device)).sum().item()

        # Calculate accuracy as a percentage
        accuracy = (correct_predictions / total_samples) * 100
        print(f"Accuracy: {accuracy:.2f}%")

    def sample_test_image(self):
        """
        Randomly samples a single image and its true label from the test dataset.

        Returns:
            tuple: A tuple containing the image tensor and its corresponding true label.
        """
        # Generate a random integer index within the range of the test dataset
        r = self.random.integers(low=0, high=len(self.test_data))
        return self.test_data[r] # Return the image and label at that index

    def export_model(self, file_name="lab6_p1.pth"):
        """
        Saves the current state dictionary of the model to a specified file.
        This allows for later loading and reuse of the trained model.

        Args:
            file_name (str): The name of the file to save the model's state_dict.
                             Defaults to "lab6_p1.pth" as per assignment.
        """
        torch.save(self.model.state_dict(), file_name)
        print(f"Model state dictionary saved to {file_name}")

    def import_model(self, file_name="lab6_p1.pth"):
        """
        Loads the model's state dictionary from a specified file.
        This restores the model to a previously saved state.

        Args:
            file_name (str): The name of the file from which to load the model's state_dict.
                             Defaults to "lab6_p1.pth" as per assignment.
        """
        # Load the state dictionary, mapping to the current device
        state_dict = torch.load(file_name, map_location=torch.device(self.device))
        self.model.load_state_dict(state_dict) # Apply the loaded state dictionary to the model
        self.model.eval() # Set model to evaluation mode after loading for consistency
        print(f"Model state dictionary loaded from {file_name}")

    def set_seed(self, seed=2025):
        """
        Sets the random seed for various libraries to ensure reproducibility.
        This includes numpy, torch, and Python's built-in random module.

        Args:
            seed (int): The seed value to be set. Fixed at 2025 as per assignment.
        """
        self.random = np.random.default_rng(seed) # Set numpy random seed
        torch.manual_seed(seed) # Set torch CPU seed
        if torch.cuda.is_available():
            torch.cuda.manual_seed_all(seed) # Set torch GPU seed if CUDA is available
        random.seed(seed) # Set Python's random seed


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