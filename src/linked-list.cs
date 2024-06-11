using System;

public class Utility {
    
    public Utility()
    {
        
    }
    
    public void TraverseAndPrintLinkedList(Node previous)
    {
        Console.WriteLine(previous.GetItem());
        if (previous.GetNext() == null) 
        {
            return;
        }
        TraverseAndPrintLinkedList(previous.GetNext());
    }
    
    public void InsertNodeAtEnd(Node previous, ref int counter) 
    {
        if (previous.GetNext() == null) {
        // reached the end of the list
            Node node = new Node(counter);
            counter++;
            
            previous.SetNext(node);
            
            return;
        }
    
        InsertNodeAtEnd(previous.GetNext(), ref counter);
    }
}

// Very basic implementation of a linked list with traversal
public class Main
{    
    private static Utility util = new Utility();
    
    public static void Main(string[] args)
    {
        
        int counter = 2;
        Node head = new Node(1);
        util.InsertNodeAtEnd(head, ref counter);
        util.InsertNodeAtEnd(head, ref counter);
        util.InsertNodeAtEnd(head, ref counter);
        util.InsertNodeAtEnd(head, ref counter);
        util.InsertNodeAtEnd(head, ref counter);
        util.InsertNodeAtEnd(head, ref counter);
        util.InsertNodeAtEnd(head, ref counter);
        util.InsertNodeAtEnd(head, ref counter);
        util.InsertNodeAtEnd(head, ref counter);
        
        util.TraverseAndPrintLinkedList(head);
    }
    
   
}

public class Node 
{
    private Node next;
    private int item;
    
    public Node(int _item)
    {
        next = null;
        item = _item;
    }   
    
    public void SetNext(Node _next) {
        next = _next;
    }
    
    public Node GetNext() 
    {
        return next;
    }
    
    public int GetItem() 
    {
        return item;    
    }
}
