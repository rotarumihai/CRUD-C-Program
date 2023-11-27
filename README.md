# CRUD-C-Program:

# *MiniMarket Database Program*

This C++ program represents a simple database for a mini-market dealing with fruits and vegetables. The program allows users to perform CRUD (Create, Read, Update, Delete) operations on products within the mini-market.

## Table of Contents

- [Features](#features)
- [How to Use](#how-to-use)
- [Code Structure](#code-structure)
- [Improvements](#improvements)
- [Contributing](#contributing)
- [License](#license)

## Features

1. **Add Product (CREATE):**
   - Users can add new products to the database by providing details such as product name, category, quantity, price, delivery date, and expiration date.

2. **Display Products (READ):**
   - The program allows users to view all products stored in the database, including information such as product ID, name, category, quantity, price, delivery date, and expiration date.
   - Additionally, the program displays the number of products in each category.

3. **Update Product (UPDATE):**
   - Users can modify existing product details by specifying the product ID and entering the updated information.

4. **Delete Product (DELETE):**
   - Products can be removed from the database by providing the product ID.

## How to Use

1. Compile the program using a C++ compiler.
2. Run the compiled executable.
3. The program will display a menu with options:
   - 1: Add Product
   - 2: Display Products
   - 3: Update Product
   - 4: Delete Product
   - 0: Exit
4. Select the desired option by entering the corresponding number.
5. Follow the prompts to perform the chosen operation.
6. Repeat steps until choosing the "0: Exit" option to exit the program.

## Code Structure

The program consists of a main function and a class named `BazaDeDateProduse` for handling CRUD operations. The `Produs` struct represents the structure of a product. The code is organized into methods for creating, displaying, updating, and deleting products.

## Improvements

- Input validation: Enhance the program to validate user input, ensuring data integrity.
- Exception handling: Implement exception handling to gracefully handle unexpected scenarios.
- Sorting: Add an option to sort products based on various criteria (e.g., name, category, price).
- Menu refinement: Separate the menu handling into a dedicated class or function for better modularity.
- Data persistence: Include functionality to save and load data from a file for persistent storage between program runs.

## Contributing

Contributions are welcome! Feel free to open issues or submit pull requests to improve the program.

## License

This program is licensed under the [MIT License](LICENSE).
