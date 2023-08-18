#include<iostream>
#include<stdio>
#include<string>

using namespace std;

struct Node{
    Node* prev = NULL;
    Node* next = NULL;
    const string url;
    
    Node(const string & url) : url(url){}
};

class BrowserHistory{
private:
    Node* curr=NULL;
public:
    BrowserHistory(string homepage){
        curr = new Node(homepage);
    }
    
    void visit(string url){
        curr -> next = url;
        curr->next ->prev = curr;
        curr = curr->next;
    }
    
    string back(int steps){
        while(curr->prev !=NULL && steps-- > 0){
            curr = curr->prev;
        }
        return curr->url;
    }
    
    string forward(int steps){
        while(curr->next !=NULL && step-- >0){
            curr = next;
        }
        return curr->url;
    }
};

int main() {
    BrowserHistory history("https://www.google.com");

    history.visit("https://www.openai.com");
    history.visit("https://www.github.com");
    history.visit("https://www.wikipedia.org");

    cout << "Current page: " << history.forward(1) << endl;
    cout << "Current page: " << history.forward(1) << endl;
    cout << "Current page: " << history.back(2) << endl;

    return 0;
}

