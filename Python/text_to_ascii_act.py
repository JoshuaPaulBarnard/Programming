# This script takes in a text string and a font type (either "standard", "slant" or "3d") and returns the text in the chosen font type. If the font type is "standard", it returns the text as is. If it's "slant", it shifts each letter of the text one position to the right in the alphabet. If it's "3d", it shifts each letter two positions to the right in the alphabet.

def ascii_art(text, font="standard"):
    """
    Create ASCII Art from text.

    Parameters:
    text (str): Text to convert to ASCII art.
    font (str): Font type (standard, slant, 3d). Default is "standard".

    Returns:
    str: ASCII art representation of text.
    """
    if font == "standard":
        return text
    elif font == "slant":
        result = ""
        for char in text:
            if char.isalpha():
                ascii_offset = ord('a') if char.islower() else ord('A')
                result += chr(ord(char) + 1) if char.islower() else chr(ord(char) + 1)
            else:
                result += char
        return result
    elif font == "3d":
        result = ""
        for char in text:
            if char.isalpha():
                ascii_offset = ord('a') if char.islower() else ord('A')
                result += chr(ord(char) + 2) if char.islower() else chr(ord(char) + 2)
            else:
                result += char
        return result
    else:
        return "Invalid font type. Please choose 'standard', 'slant' or '3d'."




# Example:  
text = "Hello World"
font = "slant"
print(ascii_art(text, font))