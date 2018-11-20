Store-Hunter

Problem Statement:
Say that I have a list of products and coupons.

products = [{name: “Product 1”,  price: 30}, {name: “Product 2”, price: 40}]
coupons = [{name: “Product 1”, discount_percentage: 10, shop: “Shop 1”}, {name: “Product 1”, discount_percentage: 8, shop: “Shop 2”}, {name: “Product 2”, discount_percentage: 5, shop: “Shop 4”}].
 
Given a recipe of the following kind:

recipe = {name: “Recipe 1”, ingredients: [“Product 1”, “Product 6” ...]}
 
Write a program that will list all the shops I need to go to make the recipe as cheap as possible.


Programming Language -C++


Product Details like product name and price are stored in product.txt

Coupon related information like discount%,shop name is stored in coupon.txt

Input:User should give the recipe name and ingredients required.
Output:Displays the cheapest shop that sells each ingredient (Attached as .png file)

Time Complexity:O(n^2)
where n is the total number of products

