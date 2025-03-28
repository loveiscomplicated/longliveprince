def output(number):
    str_number = str(number)
    space = 6 - len(str_number)
    if (space < 6) & (space > 0):
        return (' ' * space) + str_number
    else:
        return str_number

size = int(input('Enter USB size (GB): '))
size_byte = size * (2**30)

pixel_num = 800 * 600

# 이미지 한 개당 용량
gif = pixel_num / 5
jpeg = pixel_num * 3 / 25
png = pixel_num * 3 / 8
tiff = pixel_num * 6

gif_images = int(size_byte // gif)
jpeg_images = int(size_byte // jpeg)
png_images = int(size_byte // png)
tiff_images = int(size_byte // tiff)

print(f'{output(gif_images)} image(s) in GIF format can be stored')
print(f'{output(jpeg_images)} image(s) in JPEG format can be stored')
print(f'{output(png_images)} image(s) in PNG format can be stored')
print(f'{output(tiff_images)} image(s) in TIFF format can be stored')
