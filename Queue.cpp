#include"Queue.h"

Node::Node() {
    next = NULL;
}

Node::Node(Node_entry item, Node *add_on) {
    entry = item;
    next = add_on;
}

Queue::Queue() {
    front = rear = NULL;
}

Queue::Queue(const Queue &original){
	front = original.front;
	rear = original.rear;
}

Queue::~Queue(){
	while(front!=NULL){
		serve();
	}
}

bool Queue::append(const Queue_entry &item) {
    Node *new_rear = new Node(item);
    if (new_rear == NULL) return false;
    if (rear == NULL)
        front = rear = new_rear;
    else {
        rear->next = new_rear;
        //(*rear).next = new_rear;
        rear = new_rear;
    }
    return true;
}

bool Queue::serve() {
    if (front == NULL) return false;
    Node *old_front = front;
    front = old_front->next;
    if (front == NULL) rear = NULL;
    delete old_front;
    return true;
}

bool Queue::retrieve(Queue_entry &item) const {
    if (front == NULL)
        return false;
    item = front->entry;
    return true;
}

int Queue::size() {
    Node *aux = front;
    int count = 0;
    while (aux != NULL) {
        aux = aux->next;
        count++;
    }
    return count;
}

bool Queue::empty() const{
    if (front==rear)
        return true;
    else
        return false;
}

void Queue::print(){
	int x;
	Queue Aux;
	while(front!=NULL){
		retrieve(x);
		serve();
		Aux.append(x);
		cout << " " << x;
	}
	while(Aux.front!=NULL){
			Aux.retrieve(x);
			Aux.serve();
			append(x);
		}
}

void Queue::operator = (const Queue &original){
	front=original.front;
	rear=original.rear;
}

void Queue::concatena(Queue &l1, Queue &l2){
	cout << "teste";
	int x;
	Queue Aux;
	Aux.front = l2.front;
	Aux.rear = l2.rear;
	front=l1.front;
	rear=l1.rear;
	//cout << "teste" << endl << endl;
	while (!Aux.empty()){
		Aux.retrieve(x);
		cout << x << endl;
		Aux.serve();
		append(x);
		//;
	}
}
