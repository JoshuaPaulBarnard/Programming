import secrets
import string

# Function to create a custom character set
def create_custom_charset(exclude_chars):
    # Define character sets
    lowercase = string.ascii_lowercase
    uppercase = string.ascii_uppercase
    digits = string.digits
    punctuation = string.punctuation
    
    # Combine all character sets
    all_chars = lowercase + uppercase + digits + punctuation
    
    # Remove excluded characters
    for char in exclude_chars:
        all_chars = all_chars.replace(char, "")
    
    return all_chars


# 

# Define password length
length = 16

# Characters to exclude (customize this list as needed)
exclude_chars = ".,:;<>{}O'`[]()|/\\'\""

# Create custom character set
custom_charset = create_custom_charset(exclude_chars)

# Generate the password
password = ''.join(secrets.choice(custom_charset) for _ in range(length))

print(password)
