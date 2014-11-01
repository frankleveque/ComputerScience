package datastructures;

/** 
 * A node object with head and tail references for use in linked lists.
 * @author Frank Leveque
 * @creator Frank Leveque
 */
class Node{
    Object obj = null;
    public Node previous = null;
    public Node next = null;

    public Node(Object obj) {
        this.obj = obj;
    }
}

/** 
 * Data structure comprised of nodes that can be traversed backwards
 * and forwards
 * @author Frank Leveque
 * @creator Frank Leveque
 */
public class DoubleLinkedList{

    public Node head = null;
    public Node tail = null;

    public void addFront(Node node){
        if (head==null){
            head = node;
            tail = head;
        } else{
            Node temp = node;
            head.previous = temp;
            temp.next = head;
            head = temp;
        }
    } 

    public void addBack(Node node){
        if (head==null){
            head = node;
            tail = head;
        }else{
            Node temp = node;
            tail.next = temp;
            temp.previous = tail;
            tail = temp;
        }
    } 

    public Object removeNode(Node node){
        Object temp = node.obj;
        if(head==null)
            return null;
        else if(head==tail && head!= null){
            head = null;
            tail = null;
            return temp;
        } else if(node==head){
            node.next.previous = null; 
            head = node.next;
            return temp;
        } else if(node==tail){
            node.previous.next = null; 
            tail = node.previous;
            return temp;
        }
        else {
            node.previous.next = node.next;
            node.next.previous = node.previous;
            return temp;
        }
    }

    public Object removeFirst(){
        return removeNode(head);
    }

    public Object removeLast(){
        return removeNode(tail);
    }

    public void printForwards(){
        if(head==null){
            return;
        }
        else{
            Node currentNode = head;
            while(currentNode != null)
            {
                System.out.println(currentNode.obj);
                currentNode = currentNode.next;
            }
        }
    }

    public void printBackwards(){
        if(tail==null){
            return;
        }
        else{
            Node currentNode = tail;
            while(currentNode != null)
            {
                System.out.println(currentNode.obj);
                currentNode = currentNode.previous;
            }
        }
    }
}