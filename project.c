#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define limit 100 // Max number of products 

// Structure to store product info
struct Product {
  int id;
  char product_name[50];
  float price;
  int quantity;
};

struct Product products[limit]; // Array to store product info
int num_products = 0; //  tracks the number of products 

// Function prototypes
void add ();
void ListSoldOutGood ();
void search ();
void sell ();
void ListSoldGoodQuantities ();
void edit();
void delete();

int main(){
 int choice;

  while (1) {
    printf("\nDepartmental Store Management System\n");
    printf("1. Add Product\n");
    printf("2. sell Product\n");
    printf("3. Search Product\n");
    printf("4. ListSoldOutGood\n");
    printf("5. ListSoldGoodQuantities\n");
    printf("6. edit product\n");
    printf("7. delete\n");
    printf("8. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        add ();
        break;
        case 2:
        sell();
        break;
      case 3:
        search();
        break;
      case 4:
        ListSoldOutGood();
        break;
      case 5:
       ListSoldGoodQuantities();
        break;
        case 6:
        edit();
        break;
        case 7:
        delete();
        break;
      case 8:
        printf("Exiting...\n");
        exit(0);
      default:
        printf("Invalid choice!\n");
    
  }
  }
  return 0;

}    

void add() {
  if (num_products == limit) {
    printf("Maximum number of products reached!\n");
    return;
  }
  
  struct Product new_product;  //make new product
  
  //enter new product data
  printf("Item id: ");
  while(scanf("%d", &new_product.id) != 1 && new_product.id < 0) { //make sure input is a positve intger
    printf("Invalid input! Please enter a non-negative integer for the item id: ");
    scanf("%*[^\n]"); 
    scanf("%*c");  
    //check for duplicate id
  }for (int i = 0; i < 100; i++) {
    if (products[i].id == new_product.id) {
        printf("Duplicate found! \n please enter a new id:");
        while(scanf("%d", &new_product.id) != 1 && new_product.id < 0) {
    printf("Invalid input! Please enter a non-negative integer for the item id: ");
    scanf("%*[^\n]"); 
    scanf("%*c");     
  }
    }
}

  printf("Enter product name: ");
  scanf("%*[^\n]"); 
  scanf("%*c");     
  fgets(new_product.product_name, sizeof(new_product.product_name), stdin);
  
  


  

  printf("Enter price: ");
  while(scanf("%f", &new_product.price) !=1 && new_product.price<0 ){ //make sure input is a positve intger
    printf("invalid input");
    scanf("%*[^\n]");
  }

  printf("Enter quantity: ");
  while(scanf("%d", &new_product.quantity) !=1 && new_product.quantity<0){
      printf("invalid input");
  }

  products[num_products] = new_product;
  num_products++;

  printf("Product added successfully!\n");
}
//search for product by id
void search() {
    int id;
    printf("enter product id you want to search for: ");
    while(scanf("%d", &id) !=1 && id<0 ){ //make sure input is a positve intger
    printf("invalid input a positve intger");
    scanf("%*[^\n]");
  }
    
    for (int i = 0; i < num_products; i++) {
        if (products[i].id == id) {
        printf ("id: %d\n name: %s\n price: %2.lf\n amount: %d",products[i].id,products[i].product_name,products[i].price,products[i].quantity);
     }else {
        printf("product not found");
        }
}
}

void sell() {
  int id, n;

  // Search for product by ID
  printf("Enter the ID of the product you want to sell: ");
  while (scanf("%d", &id) != 1 || id < 0) { // Ensure positive integer input
    printf("Invalid input! Please enter a positive integer for the ID: ");
    scanf("%*[^\n]"); // Clear previous input
  }

  int found = 0; // Flag to track if product is found
  for (int i = 0; i < num_products; i++) {
    if (products[i].id == id) {
      found = 1; // Set flag if product found
      printf("ID: %d\nName: %s\nPrice: %.2lf\nQuantity: %d\n", products[i].id, products[i].product_name, products[i].price, products[i].quantity);

      printf("How much do you want to sell? ");
      while (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input! Please enter a non-negative quantity: ");
        scanf("%*[^\n]"); // Clear previous input
      }

      if (n > products[i].quantity) {
        printf("Not enough product to sell!\n");
      } else {
        products[i].quantity -= n;
        printf("Amount: %d\n", products[i].quantity);
        printf("Product successfully sold!\n");
      }
      break; // Exit loop after finding and selling the product
    }
  }

  if (!found) {
    printf("Product with ID %d not found.\n", id);
  }
}

//lists products with zero quantity
void ListSoldOutGood() {

  int i;
for (int i = 0; i < num_products; i++) {
        if (products[i].quantity == 0) {
        printf (" name: %s\n ",products[i].product_name);}
else {
  printf("no sold out products!\n");}

}}
// displays the info of all products with quantity zero
void ListSoldGoodQuantities() {
  int i;
for (int i = 0; i < num_products; i++) {
        if (products[i].quantity == 0) {
        printf (" id: %d\n name: %s\n price: %2.lf\n amount: %d\n",products[i].id,products[i].product_name,products[i].price,products[i].quantity);
        }
else {
  printf("no sold out products!\n");}
}
}

void edit() {

  int id;

  // Search for product using ID
  printf("Please input the ID of the product you want to edit: ");
  while (scanf("%d", &id) != 1 && id < 0) {  // Ensure positive integer input
    printf("Invalid input! Please enter a positive integer for the ID: ");
    scanf("%*[^\n]"); // Clear previous input
  }

  int found = 0; // Flag to track if product is found

  for (int i = 0; i < num_products; i++) {
    if (products[i].id == id) {
      found = 1;  // Set flag if product is found

      printf("Current ID: %d\n", products[i].id);

      // Get new product details
      printf("New product ID: ");
      while (scanf("%d", &products[i].id) != 1 && products[i].id < 0) {
        printf("Invalid input! Please enter a positive integer for the ID: ");
        scanf("%*[^\n]"); // Clear previous input
      }

      printf("Current name: %s\n", products[i].product_name);
      printf("New product name: ");
      scanf("%s", &products[i].product_name);

      printf("Current price: %.2f\n", products[i].price);
      printf("New product price: ");
      while (scanf("%f", &products[i].price) != 1 && products[i].price < 0) {
        printf("Invalid input! Please enter a non-negative price: ");
        scanf("%*[^\n]"); // Clear previous input
      }

      printf("Current quantity: %d\n", products[i].quantity);
      printf("New product quantity: ");
      while (scanf("%d", &products[i].quantity) != 1 && products[i].quantity < 0) {
        printf("Invalid input! Please enter a non-negative quantity: ");
        scanf("%*[^\n]"); // Clear previous input
      }

      printf("Product edited successfully!\n");
      break; // Exit loop after editing the found product
    }
  }

  if (!found) { // Check if product wasn't found
    printf("Product with ID %d not found.\n", id);
  }
}


 void delete() {
  int id, index_to_delete = -1;
  printf("Enter the ID of the product that you want to delete: ");
  while (scanf("%d", &id) != 1 && id < 0) {
    printf("Invalid input! Please enter a positive integer for the ID: ");
    scanf("%*[^\n]"); // Clear previous input
  }

  for (int i = 0; i < num_products; i++) {
    if (products[i].id == id) {
      index_to_delete = i;
      break; // Exit loop after finding the product
    }
  }

  if (index_to_delete == -1) {
    printf("Product with ID %d not found.\n", id);
    return;
  }

  // Shift remaining elements to remove deleted product
  for (int i = index_to_delete; i < num_products - 1; i++) {
    products[i] = products[i + 1];
  }

  num_products--;

  printf("Product with ID %d deleted successfully!\n", id);
}


