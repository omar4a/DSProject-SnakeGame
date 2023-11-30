#include <iostream>

using namespace std;

class Snake {

    private:

        class Node {

        public: 

        int x, y;

        Node *next;

        Node() : x(0), y(0), next(0) {}

        Node (int x, int y){
            
            this->x = x;

            this->y = y;

            next = NULL;
        }

        };

    public:

        Node *head, *tail; // These are public temporarily for tests.

        Snake () : head(0), tail(0) {}


        bool empty(){
            
            return head == NULL;
        }

        void enqueue(int& x, int& y){

            Node *newNode = new Node(x,y);

            if(empty()) {head = tail = newNode;}

            else {

                tail->next = newNode;

                tail = newNode;

            }

        }

        void dequeue(){ // So far this has no use.

            if (empty()) {cerr << "Snake queue is empty. Cannot dequeue." << endl;}

            else{

                Node * ptr = head;

                head = head->next;

                delete ptr;

                if (empty()) {tail = NULL;}

            }
        }

        void front(int& x, int& y){

            if (empty()) {cerr << "Snake queue is empty. Cannot return front." << endl;}

            else{

                x = head->x;
                y = head->y;
            }
        }

};