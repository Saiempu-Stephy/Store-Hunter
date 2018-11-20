//Store Hunter -C++ //
//Developed by Stephy //
//Standard Library

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

class product
{
	public:
	float price;				//Stores price of Product
	string pdt_name;			//Stores Product name
};

class coupon
{
	public:
	string name;				//Stores Product name
	string shop;				//Stores Shop name where the product is available
	int discount_percentage;		//Stores discount % of the product in the shop
	
};


int main() {
    int i,num=0,no_of_ingredients;
    vector<float> min_price;			//Store the cheapest Price of all products
    product* p = new product[10];		//Creating an array of class Product
    coupon* c = new coupon[10];			//Creating an array of class Coupon
    vector<string> shop_list;			//Shops having cheapest price for a product
    string Recipe_name;
    
    ifstream inFile;
    
    inFile.open("product.txt");
    
    if (!inFile) {
        cout << "Unable to open file";     
    }
    
    while (!inFile.eof()) {			//Reading the product name and price from product.txt
    	inFile>>p[num].pdt_name;	
    	inFile>>p[num].price;
    	min_price.push_back(p[num].price);
        num++;
    }
   int num_of_pdt = num-1;
   inFile.close();
   num=0;
   inFile.open("coupon.txt");
    if (!inFile) {
        cout << "Unable to open file";  
    }
    
    while (!inFile.eof()) {			//Reading product names and discount % available in different shops from coupon.txt
    	inFile>>c[num].name;
    	inFile>>c[num].discount_percentage;
    	inFile>>c[num].shop;
        num++;
    }
    inFile.close();
    
    float discount_price;
    int shop_index;
    vector<int> cheap_shop;			  
    for (i=0;i<num_of_pdt;i++)
    {
    	for(int j=0;j<num-1;j++)
    	{
    		if(p[i].pdt_name==c[j].name)
    		{
    			discount_price=p[i].price-((p[i].price*c[j].discount_percentage)/100);	//calculates the discount price
    			if(discount_price<min_price[i])						
    			{
    				min_price[i] = discount_price;	//finding the cheapest price available for a product
    				shop_index = j;			
    			}
    				
    		}
    	}
    	cheap_shop.push_back(shop_index);
    
    }
    string ingredient;
    vector<string> Recipe_ingredient;
    int to_continue=1;
    while(to_continue!=0)				//getting input from the user
    {
    	cout<<"Enter recipe name"<<endl;
    	cin>>Recipe_name;
    	cout<<"Enter number of ingredients"<<endl;
    	cin>>no_of_ingredients;
    	cout<<"Enter the ingredients"<<endl;
    	for(i=0;i<no_of_ingredients;i++)
    	{
    		cin>>ingredient;
    		Recipe_ingredient.push_back(ingredient);
    		for(int j=0;j<num_of_pdt;j++)
    		{
    			if(p[j].pdt_name==ingredient)
    			shop_list.push_back(c[cheap_shop[j]].shop);
   	 	}
   	 }
   
    
    	for(i=0;i<shop_list.size();i++)
   	 {
   		 cout<<Recipe_ingredient[i]<<"--->"<<shop_list[i]<<endl;
   	 }
    	cout<<"Do you want to see for another recipe, Press 1 to continue otherwise press 0"<<endl;
   	cin>>to_continue;
    	shop_list.clear();
	Recipe_ingredient.clear();
    
    }
    
    
    return 0;
}
//Thank you //
