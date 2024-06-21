#include "recipe.h"

int main(){
    
    RecipeBook book1;
    char input;
    int sequenceNumber;
    string header;
    string description;
    string title;
    int pageNum;
    int size;
    cout << "Welcome to your recipe book" << endl << endl;
    cout << "What is the title of your recipebook?" << endl;
    getline(cin, title);
    book1.setTitle(title);
    do{
        Recipe recipe1;
        cout << endl;
        cout << "(C)reate" << endl;
        cout << "(R)ead" << endl;
        cout << "(U)pdate" << endl;
        cout << "(D)elete" << endl;
        cout << "(Q)uit" << endl;
        cin >> input;

        switch(input){
            case 'C':
            case 'c':
                cout << "Please enter the name of the recipe." << endl;
                cin.ignore();
                getline(cin, title);
                cout << "Please enter the description of the recipe." << endl;
                getline(cin, description);
                recipe1.setTitle(title);
                recipe1.setDescription(description);
                cout << "Please enter the page number of this recipe." << endl;
                cin >> pageNum;
                recipe1.setPageNum(pageNum);
                cout << "How many steps does your recipe have?" << endl;
                cin >> size;
                for(int i = 0; i < size; i++){
                    cout << "Please enter the sequence number of your step." << endl;
                    cin >> sequenceNumber;
                    cout << "Please enter the step header." << endl;
                    cin.ignore();
                    getline(cin, header);
                    cout << "Please enter the step description." << endl;
                    getline(cin, description);
                    recipe1.Create(RecipeStep(sequenceNumber, header, description));
                }
                book1.Create(recipe1);
                break;
            case 'R':
            case 'r':
                cout << book1 << endl;
                break;
            case 'U':
            case 'u':
                cout << "Would you like to update your book(b) or recipe(r)?" << endl;
                cin >> input;
                if(input == 'b' || input == 'B'){
                    cout << "Please enter the page number of the recipe you would like to update." << endl;
                    cin >> pageNum;
                    book1.Update(pageNum);
                    cout << "Here are your updated values." << endl;
                    cout << book1 << endl;
                }
                else if(input == 'r' || input == 'R'){
                    cout << "Please enter the page number of the recipe you would like to update." << endl;
                    cin >> pageNum;
                    cin.ignore();
                    cout << "Please enter the sequence number of the recipe step you would like to update." << endl;
                    cin >> sequenceNumber;
                    recipe1 = book1.Get(pageNum); //make a definition for get in recipebook that loops through the array and returns a recipe
                    recipe1.Update(sequenceNumber);
                    cout << "Here are your updated values." << endl;
                    cout << recipe1 << endl;
                
                
                }
                else{
                    cout << "Sorry I can not do that." << endl;
                }
                break;
            case 'D':
            case 'd': 
                cout << "Would you like to delete from your book(b) or recipe(r)?" << endl;
                cin >> input;
                if(input == 'b' || input == 'B'){
                    cout << "Please enter the page number of the recipe you would like to delete." << endl;
                    cin >> pageNum;
                    book1.Delete(pageNum);
                    cout << "Here is your updated values." << endl;
                    cout << book1 << endl;
                }
                else if(input == 'r' || input == 'R'){
                    cout << "Please enter the page number of the recipe you would like to delete." << endl;
                    cin >> pageNum;
                    cout << "Please enter the sequence number of the recipe step you would like to delete." << endl;
                    cin.ignore();
                    cin >> sequenceNumber;
                    recipe1 = book1.Get(pageNum);
                    recipe1.Delete(sequenceNumber);
                    cout << "Here are your update values." << endl;
                        cout << recipe1 << endl;
                
                }
                else{
                    cout << "Sorry I can not do that." << endl;
                }
                break;
            case 'q':
            case 'Q':
                return 0;
            default:
                cout << "Sorry I can not do that." << endl;
        }
    }while(input != 'q' || input != 'Q');
    
}