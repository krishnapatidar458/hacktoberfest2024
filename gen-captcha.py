# first install captcha pillow
# pip install captcha pillow

from captcha.image import ImageCaptcha
from PIL import Image
import random
import string

def generate_captcha_text():
    letters = string.ascii_uppercase
    captcha_text = ''.join(random.choice(letters) for i in range(5))
    return captcha_text

def generate_captcha_image(captcha_text):
    image = ImageCaptcha()
    image.generate(captcha_text)
    image.write(captcha_text, f"{captcha_text}.png")

def display_captcha_image(captcha_text):
    image_path = f"{captcha_text}.png"
    image = Image.open(image_path)
    image.show()

def main():
    captcha_text = generate_captcha_text()
    generate_captcha_image(captcha_text)
    display_captcha_image(captcha_text)
    
    user_input = input("Enter the CAPTCHA text: ")
    
    if user_input == captcha_text:
        print("You're a human!")
    else:
        print("Sorry, that's incorrect. Are you a robot?")

if __name__ == "__main__":
    main()
