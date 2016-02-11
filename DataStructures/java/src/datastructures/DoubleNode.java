package DataStructures;

/** 
 * A node object with head and tail references for use in linked lists.
 * @author Frank Leveque
 * @creator Frank Leveque
 */
public class DoubleNode{
    public DoubleNode previous = null;
    public DoubleNode next = null;
    private Object data = null;

    public DoubleNode(Object obj) {
        this.data = obj;
    }

    public Object getData(){
        return data;
    }

    public void setData(Object data){
        this.data = data;
    }
}
