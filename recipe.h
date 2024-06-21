#include <iostream>
using namespace std;

class RecipeStep{
    friend ostream& operator<<(ostream& o, const RecipeStep& rs);
    private:
        int sequenceNumber;
        string header;
        string description;
    public:
        RecipeStep();
        RecipeStep(int sequenceNumber, string header, string description);
        int getSeqNum() const;
        string getHeader() const;
        string getDescription() const;
        void setSeqNum(int sequenceNumber);
        void setHeader(string header);
        void setDescription(string descripiton);
};
class Recipe{
    friend ostream& operator<<(ostream& o, const Recipe& r);
    private:
        string title;
        string description;
        RecipeStep* steps; //pointer of type RecipeStep named steps
        int size, capacity;
        int pageNum;
        void resize(); //growth algorithm
    public:
        Recipe();
        Recipe(const Recipe& r);// copy constructor Rule of 3 1/3
        Recipe(string title, string description);
        Recipe(string title, string description, int pageNum);
        ~Recipe(); //Destructor rule of 3 2/3
        Recipe& operator=(const Recipe& r); // assignment operator overload rule of 3 3/3
        string getTitle() const;
        string getDescription() const;
        int getPageNum() const;
        void setTitle(string title);
        void setDescription(string description);
        void setPageNum(int pageNum);
        void Create(const RecipeStep& rs);
        RecipeStep Read() const;
        void Update(int sequenceNumber);
        void Delete(int sequenceNumber);
};
class RecipeBook{
    friend ostream& operator<<(ostream& o, const RecipeBook& rb);
    private:
        string title;
        Recipe* recipes; // pointer of type recipe named recipes
        //int pageNum;
        int size, capacity;
        void resize(); //growth algorithm
    public:
        RecipeBook();
        //RecipeBook(string title);
        RecipeBook(const RecipeBook& rb); //copy constructor rule of 3 1/3
        RecipeBook& operator=(const RecipeBook& rb); //assignment operator overlaod rule of 3 2/3
        ~RecipeBook(); //destructor rule of 3 3/3
        string getTitle() const;
        int getPageNum() const;
        void setTitle(string title);
        void setPageNum(int pageNum);
        void Create(const Recipe& r);
        Recipe Read(int pageNumber)const;
        void Update(int pageNum);
        void Delete(int pageNum);
        Recipe Get(int pageNum);


};