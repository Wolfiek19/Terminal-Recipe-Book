#include "recipe.h"
//======================================RecipeStep====================================
RecipeStep::RecipeStep(){ //RecipeStep default constructor 
    sequenceNumber = 0;   //setting sequence num to 0
    header = " ";         // setting header to blank
    description = " ";    //setting descripition to blacnk
    
}
RecipeStep::RecipeStep(int sequenceNumber, string header, string description){ //RecipeStep paramaterized constructor 
    this -> sequenceNumber = sequenceNumber; //private seqnum = to passed in seqnum
    this -> header = header;                 //private header = to passed in header
    this -> description = description;       //private descripiton = to passed in descripiton 
   
}
ostream& operator<<(ostream& o, const RecipeStep& rs){ //recipestep insertion overload 
    o << "step " << rs.sequenceNumber << " | " << rs.header << " | " << rs.description << endl;
    return o; //returning recipe step sequence number, header and description
}
int RecipeStep::getSeqNum() const{
    return sequenceNumber; // getter for sequence numeber, returning private sequence number
}

string RecipeStep::getHeader() const{
    return header; //getter for header, returning private header 
}
string RecipeStep::getDescription() const{
    return description;  //getter for recipestep descritpion, return private descripiton 
}
void RecipeStep::setSeqNum(int sequenceNumber){
    this -> sequenceNumber = sequenceNumber;  //setting for sequence number, setting the private sequence number = to passed in sequence number 
}
void RecipeStep::setHeader(string header){
    this -> header = header; //setter for header, setting private header to the passed in header
}
void RecipeStep::setDescription(string description){
    this -> description = description; //setter for description, setting the private descripiton to passed in description 
}
//======================================Recipe========================================
Recipe::Recipe(){ //default constructor for Recipe
    title = " "; //sstting title to blank
    description = " ";  //setting description to blank
    capacity = 5;   //setting the capacity of the array to 5 
    size = 0;      // setting the size of the array to 0
    pageNum = 0; //setting page number = 0, used as an ID for the RecipeBook class
    steps = new RecipeStep[capacity]; //creating a dynamically allocated array named steps that hold reipe steps
}
Recipe::Recipe(const Recipe& r){ //copy constructor for Recipe
    //copy static data
    capacity = r.capacity;
    size = r.size;
    title = r.title;
    description = r.description;
    pageNum = r.pageNum;

    //Deep copy
    steps = new RecipeStep[capacity]; //creating a dynamically allocated array named steps that hold reipe steps
    for(int i = 0; i < size; i++){ //iterating through the array 
        steps[i] = r.steps[i]; //assigning the values of the new array = to the values of the array we are copying from 
    }
}
ostream& operator<<(ostream& o, const Recipe& r){ //insertion overload for recipe clas
    
    o << "Title: " << r.getTitle() << endl; //used to print the title of the recipe book to the terminal 
   
    o << "Description: " << r.getDescription() << endl; //used to print the decripiton of the recipe to the terminal 
    o << "Page Number: " << r.getPageNum() << endl;
    for(int i = 0; i < r.size; i++){ //iterate through the array 
        o << r.steps[i] << endl; // printing the objects in the steps array, works becuase of the recipestep insertion overload 
    }
    return o; //returning o to print to the console 
}
Recipe::Recipe(string title, string description){ //constructor (might be useless)
    this -> title = title;
    this -> description = description;
    capacity = 5;
    size = 0;
    steps = new RecipeStep[capacity];
}
Recipe::Recipe(string title, string description, int pageNum){ //constructor (might be useless)
    this -> title = title;
    this -> description = description;
    this -> pageNum = pageNum;
    capacity = 5;
    size = 0;
    steps = new RecipeStep[capacity];
}
Recipe::~Recipe(){ //destructor used to clear up data on the heap 
    delete [] steps;
}
void Recipe::resize(){ //resize function containing the growth algorithm 
    RecipeStep* tmp = new RecipeStep[capacity + 1]; //creating a recipestep array named tmp and allocating it on the heap with 1 extra capacity
    for(int i = 0; i < size; i++){ //iterate through the array that we want to grow
        tmp[i] = steps[i]; // placing objects from the original steps array into th tmp array
    }
    delete [] steps; //cleaning up the steps array on the heap
    steps = tmp; //setting steps = to tmp
    capacity = capacity + 1; // setting capacity to the original capacity size + 1
}
Recipe& Recipe::operator=(const Recipe& r){ //assignment operator overlaod 
    if(this != &r){ //if statement to check for self assignment 
        size = r.size; // setting the new size = to the current arrays size
        capacity = r.capacity; //setting the new capacity = to the current arrays capacity 
        title = r.title; //setting the new title = to the current title 
        description = r.description; //setting the new description = to the current description  
        pageNum = r.pageNum; // setting the new pageNum = to the current page num 

        delete [] steps; //deleting the data on the heap that is currently in the steps array 
        steps = new RecipeStep[capacity]; //creating a new array on the heap that is also named steps
        for(int i = 0; i < size; i ++){ //iterate through the array
            steps[i] = r.steps [i]; //assign the new objects in step to the current ones 
        }
    }
    return *this; // return a dereference to the current object 
}
string Recipe::getTitle() const {
    return title; //getter for title, returning the private title 
}
string Recipe::getDescription() const {
    return description; //getter for description, returning the private description 
}
int Recipe::getPageNum() const{
    return pageNum; //getter for pageNum, returning the private pageNum 
}
void Recipe::setTitle(string title){
    this -> title = title; //setter for title 
}
void Recipe::setDescription(string description){
    this -> description = description; //setter for description
}
void Recipe::setPageNum(int pageNum){
    this -> pageNum = pageNum; //setter for page number
}
void Recipe::Create(const RecipeStep& rs){ //create fucntion for recipe taking in a recipe step objects 
    int sequenceNumber;
    string header;
    string description;
    if(size >= capacity){ // if statement used to check if the size of the array is >= to the capcity of array 
        resize(); // if yes we resize
    }
    steps[size++] = rs; // increasing the size of the steps and assigns the values of RS to that index of the array
}
RecipeStep Recipe::Read() const { //Recipe read fucntion 
    cout << "Here are your current recipe steps." << endl;
    for(int i = 0; i < size; i++){ //iterate through the steps array 
        cout << steps[i] << endl; //print out the current recipe steps 
    }
    return RecipeStep(); //returns recipestep 
}
void Recipe::Update(int sequenceNumber){ //update function for the steps array that takes in a sequence number as an ID
    string header;
    string description;
    if(this-> pageNum == pageNum){
        for(int i = 0; i < size; i++){ //iterate through the steps array     
            if(steps[i].getSeqNum() == sequenceNumber){ //if statement used to check if the sequence number the user entered is equal to a sequence number of a recipestep object 
                cout << "Please enter your updated recipe steps." << endl;
                cin.ignore();
                cout << "Please enter the updated sequence number." << endl;
                cin >> sequenceNumber;
                cout << "Please enter the updated header for the step." << endl;
                cin.ignore();
                getline(cin, header);
                cout << "Please enter the updated description for the step." << endl;
                getline(cin, description);
                steps[i].setSeqNum(sequenceNumber);
                steps[i].setHeader(header);
                steps[i].setDescription(description);
                
            }
            //break;
            //all above is just asking for user input to update the object and then setting the object to the new data, then breaking from the loop 
        }
        
    }
}
void Recipe::Delete(int sequenceNumber){  //delete function to delete a recipe step object in the steps array, taking in a sequence number of the object that is to be deleted
   int rmSeqNum = -1; // interger used to set equal to index of object to be removed
   if(this -> pageNum == pageNum){
        for(int i = 0; i < size; i++){ //iterate through the 
            if(steps[i].getSeqNum() == sequenceNumber){ //if statement to check if the user input sequence number matches a sequence number in the array
                rmSeqNum = i; // if yes we set rmseqnum = to that index
        }
    }
    if(rmSeqNum != -1){ //if statement to check if rmseqnum has been changed, because if it has that means an object to delete has been found 
        for(int i = rmSeqNum; i < size - 1; i++){ // for loop to iterate throught the array starting at the index of the object to delete 
            steps[i] = steps[i + 1]; //we then make the object at the index to delete the object that is next in line and so on 
        }
    size--; // we then essentialy delete the last item in the array which should now be empty becuase we have changed the order
   //this gives the idea that the object was deleted 
    }
  
   }
}


//======================================RecipeBook====================================
RecipeBook::RecipeBook(){ //default constructor 
    //setting all values to default values
    title = " "; 
    size = 0; 
    capacity = 5;
    recipes = new Recipe[capacity]; //dynamically allocating an array named recipes 
}
RecipeBook::RecipeBook(const RecipeBook& rb){ //copy constructor 
    size = rb.size; //setting new size = to current size
    capacity = rb.capacity; //setting new capacity = to current capacity
    title = rb.title; //setting new title = to current title 
    recipes = new Recipe[capacity]; //creating a dynamically allocated array named recipes 
    for(int i = 0; i < size; i++){ // for loop to iterate through the array
        recipes[i] = rb.recipes[i]; //copying the data from the current array to the new array 
    }
}
ostream& operator<<(ostream& o, const RecipeBook& rb){ //inesertion operator overload
       o << "Book Title: " << rb.getTitle() << endl << endl;
    for(int i = 0; i < rb.size; i++){ //itarate through the recipes array
        o << rb.recipes[i] << endl; //prints the recipes array which holds the steps array
    }
    return o;
}
RecipeBook& RecipeBook::operator=(const RecipeBook& rb){ //assignment operator overlaod 
   
   if(this != &rb){ //checking for self assignment
        size = rb.size; //setting the new size = to current sie
        capacity = rb.capacity; //setting new capacity = to current capcity 
        title = rb.title; //setting new title = to current title 
        

        delete [] recipes; //deleting the recipes data on the heap
        recipes = new Recipe[capacity]; //creating a new dynamically allocated array 
        for(int i = 0; i < size; i++){ //looping through array to copy data to the new array from the current object
            recipes[i] = rb.recipes[i];
        }
   }
   return *this; //returning a derefence to the current object 
}
Recipe RecipeBook::Get(int pageNum){
    for(int i = 0; i < size; i++){
       if(recipes[i].getPageNum() == pageNum){
        return recipes[i];
       }
       
       //something to do with leaky abstraction look at game code and try to figure out
    }
    return Recipe();
}
void RecipeBook::resize(){ //resize function containing the growth algorithm
    Recipe* tmp = new Recipe[capacity + 1]; //creating a new dynamically allocated array named tmp with a capacity +1 
    for(int i = 0; i < size; i++){ //looping through the current array 
        tmp[i] = recipes[i]; // to copy the data from the current array to the new one 
    }
    delete [] recipes; //delete the data on the heap from the old array 
    recipes = tmp; //set recipes = to tmp so we can still refer to the new array as recipes 
    capacity = capacity + 1; //increasing the capcity by 1 
}
RecipeBook::~RecipeBook(){
    delete [] recipes; //destructor to clean up data on the heap
}
string RecipeBook::getTitle() const {
    return title; //getter for title 
}
void RecipeBook::setTitle(string title){
    this -> title = title; // setter for title 
}
void RecipeBook::Create(const Recipe& r){ //create function
cout << r.getPageNum() << endl;
    if(size >= capacity){ // checking to see if the size of the array is >= to the set capcaity 
        resize(); //using the growth algorithm if it is
    }
    recipes[size++] = r; //increasing the size of recipes and setting the object at that index
    
}
Recipe RecipeBook::Read(int pageNum) const { //read function
    cout << "Here are your current recipes. " << endl;
    for(int i = 0; i < size; i++){ 
        cout << recipes[i] << endl; 
    }
    return Recipe(); 
}
void RecipeBook::Update(int pageNum){ //update function taking in a pageNum which is used as an ID 
    string title;
    string description;
    for(int i = 0; i < size; i++){ //looping through the array
        if(recipes[i].getPageNum() == pageNum){ //checking to see if the passed in page num is equal to a page num in the array
            cout << "Please enter your updated title." << endl;
            cin.ignore();
            getline(cin, title);
            cout << "Please enter your updated descirpiton. " << endl;
            getline(cin, description);
            recipes[i].setTitle(title);
            recipes[i].setDescription(description);
            break;
            //if it is we ask the user to enter their updated title and then set that title
    }
    }
}
void RecipeBook::Delete(int pageNum){ //delete function that take in a page num used as an ID
    int rmPageNum = -1; //setting this to an arbitrary value until we can set to the index of the object we want to delete 
    for(int i = 0;i < size; i++){
        if(recipes[i].getPageNum() == pageNum){ //checking to see if the page num the user entered is equal to a page num in the aray 
            rmPageNum = i; // setting the rmPageNum variable equal to the index of where the page num is
        }
    }
    if(rmPageNum != -1){ //checking to see if rmPageNum has been changed 
        for(int i = rmPageNum; i < size - 1; i++){ //if it has we loop through the array starting at that index
            recipes[i] = recipes[i + 1]; //we then essentially shift each object in the array to the left 
        }
        size--; //we then subtract the size by one to effectively delete the object that we wanted to delete
    }
    
}
