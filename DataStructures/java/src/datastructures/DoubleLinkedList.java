package DataStructures;

/** 
 * Data structure comprised of nodes that can be traversed backwards
 * and forwards
 * @author Frank Leveque
 * @creator Frank Leveque
 */
public class DoubleLinkedList{

    public DoubleNode head = null;
    public DoubleNode tail = null;

    protected void addFront(DoubleNode node){
        if (head == null){
            head = node;
            tail = head;
        } else{
            //DoubleNode temp = node;
            head.previous = node;
            node.next = head;
            head = node;
        }
    } 

    protected void addBack(DoubleNode node){
        if (head==null){
            head = node;
            tail = head;
        }else{
            DoubleNode temp = node;
            tail.next = temp;
            temp.previous = tail;
            tail = temp;
        }
    } 

    protected Object removeNode(DoubleNode node){
        Object temp = node.getData();
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

    protected Object removeFirst(){
        return removeNode(head);
    }

    protected Object removeLast(){
        return removeNode(tail);
    }

    public void printForwards(){
        if(head==null){
            return;
        }
        else{
            DoubleNode currentNode = head;
            while(currentNode != null)
            {
                System.out.println(currentNode.getData());
                currentNode = currentNode.next;
            }
        }
    }

    public void printBackwards(){
        if(tail==null){
            return;
        }
        else{
            DoubleNode currentNode = tail;
            while(currentNode != null)
            {
                System.out.println(currentNode.getData());
                currentNode = currentNode.previous;
            }
        }
    }
}
