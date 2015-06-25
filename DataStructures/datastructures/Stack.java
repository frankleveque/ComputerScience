package datastructures;

/** 
 * Implements a stack data structure from a double linked list, 
 * adds top, pop, and push operations
 * @author Frank Leveque
 * @creator Frank Leveque
 */
public class Stack extends DoubleLinkedList {

    public Object top(){ 
        if(head==null)
            return null;

        return tail.obj;
    }

    public Object pop(){
        if(head==null)
            return null;

        return removeLast();
    }

    public void push(Object elem){
        addBack(new Node(elem));
    }
}
