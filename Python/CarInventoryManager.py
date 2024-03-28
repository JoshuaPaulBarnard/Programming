

class CarInventoryManager:
    def __init__(self, inventory):
        """
        Initializes the CarInventoryManager class with a list of cars as the inventory.
        
        Parameters:
        - inventory (list): A list of dictionaries, where each dictionary represents a car and its attributes.
        """
        self.inventory = inventory

    def add_car(self, car):
        """
        Adds a new car to the inventory if it does not already exist (based on VIN).
        
        Parameters:
        - car (dict): A dictionary representing the car to add, including its VIN and other attributes.
        
        Returns:
        - str: A message indicating whether the car was added successfully or if it already exists.
        """
        for existing_car in self.inventory:
            if existing_car['VIN'] == car['VIN']:
                # If a car with the same VIN exists, return a message and do not add the car
                return f"Car with VIN {car['VIN']} already exists in the inventory."
        # If no car with the same VIN is found, add the car to the inventory
        self.inventory.append(car)
        return f"Car with VIN {car['VIN']} added successfully."

    def update_car(self, car):
        """
        Updates an existing car's attributes in the inventory based on its VIN.
        
        Parameters:
        - car (dict): A dictionary representing the car to update, including its VIN and the attributes to update.
        
        Returns:
        - str: A message indicating whether the car was updated successfully or if it was not found.
        """
        for existing_car in self.inventory:
            if existing_car['VIN'] == car['VIN']:
                # If the car is found, update its attributes and return a success message
                existing_car.update(car)
                return f"Car with VIN {car['VIN']} updated successfully."
        # If no car with the specified VIN is found, return a not found message
        return f"Car with VIN {car['VIN']} not found in the inventory."

    def search_cars(self, **kwargs):
        """
        Searches for cars in the inventory that match all specified attributes.
        
        Parameters:
        - **kwargs: Arbitrary keyword arguments representing the attributes to search for.
        
        Returns:
        - list: A list of cars that match all the specified attributes.
        """
        results = []
        for car in self.inventory:
            match = True
            for key, value in kwargs.items():
                # If any attribute does not match, set match to False and break out of the loop
                if car.get(key) != value:
                    match = False
                    break
            if match:
                # If all attributes match, add the car to the results list
                results.append(car)
        return results

    def aggregate_data(self, attribute):
        """
        Calculates the total and average of a numeric attribute for all cars in the inventory.
        
        Parameters:
        - attribute (str): The attribute for which to calculate the total and average.
        
        Returns:
        - tuple: A tuple containing the total sum and average value of the specified attribute.
        """
        total = sum(car[attribute] for car in self.inventory)
        average = total / len(self.inventory)
        return total, average

    def count_by_attribute(self, attribute):
        """
        Counts the occurrences of each unique value of a specified attribute in the inventory.
        
        Parameters:
        - attribute (str): The attribute to count occurrences for.
        
        Returns:
        - dict: A dictionary where keys are unique values of the attribute and values are the count of occurrences.
        """
        counts = {}
        for car in self.inventory:
            value = car.get(attribute)
            if value not in counts:
                counts[value] = 0
            counts[value] += 1
        return counts




# Example code
import json

json_file = 'car_inventory.json'  # Replace 'car_inventory.json' with the actual filename

with open(json_file, 'r') as file:
    # Parse the JSON file and convert it into a Python object
    inventory = json.load(file)

manager = CarInventoryManager(inventory)

# Add a new car
new_car = {
    "VIN": "6FBMF633X9GB23461",
    "make": "Toyota",
    "model": "Camry",
    "year": 2020,
    "mileage": 1000,
    "price": 25000,
    "transmission": "Automatic",
    "color": "White",
    "fuel_type": "Gasoline",
    "seating_capacity": 5,
    "engine_size": "2.5L I4",
    "features": ["Lane Departure Warning", "Apple CarPlay", "Android Auto"]
}

add_result = manager.add_car(new_car)
print(add_result)

# Update a car
updated_car = {
    "VIN": "1FBMF533X9GB23456",
    "price": 33000,
    "features": ["Convertible", "Leather Seats", "Navigation System", "Sunroof"]
}

update_result = manager.update_car(updated_car)
print(update_result)

# Search for cars
search_results = manager.search_cars(make="Toyota", model="Camry")
print(search_results)

# Aggregate data
total_price, average_price = manager.aggregate_data("price")
print(f"Total price: {total_price}, Average price: {average_price}")

# Count cars by color
counts_by_color = manager.count_by_attribute("color")
print(counts_by_color)