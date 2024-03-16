fn main() {
    let original_string = "abc";
    let target_string = "bca";

    if can_be_shifted(original_string, target_string) {
        println!("The target string can be obtained by shifting the original string.");
    } else {
        println!("The target string cannot be obtained by shifting the original string.");
    }
}


fn can_be_shifted(original_string: &str, target_string: &str) -> bool {
    // Check if the lengths of the original string and the target string are equal
    if original_string.len() != target_string.len() {
        return false;  // If they are not, it is not possible to shift the original string to get the target string
    }

    // Concatenate the original string with itself, this is to cover all possible shifts of the original string
    let concatenated_string = format!("{}{}", original_string, original_string);

    // Check if the target string is a substring of the concatenated string
    // If it is, it means the original string can be shifted some number of times to get the target string
    concatenated_string.contains(target_string)
}