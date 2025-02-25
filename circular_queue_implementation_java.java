// this program demonstrates circular queue in which customer places order and if pizza is available to serve then they take orders and serve in order such  that first come first serve, if already pizzas are finished but orderes are coming then notify pizzas are not available
import java.util.*;
class pizza{
    int N;
    int[] arr;
    int front;
    int rear;
    int temp;
    int serve;
    
    pizza()
    {
        N = 5;
        front = -1;
        rear = -1;
        arr = new int[N];
    }
    
   
    void enqueue(int data)
    {
        if(front==-1 && rear==-1)
        {
            front=rear=0;
            arr[rear]=data;
        }
        else if(((rear+1)%N)==front)
        {
            System.out.println("Queue is full , Cannot accept more orders");
        }
        else
        {
            rear=(rear+1)%N;
            arr[rear]=data;
        }
    }
    
    void serveOrder(){
        if(front==-1 && rear==-1)
        {
            System.out.println("No orders to Serve");
        }
        else if(front==rear){  //only one element left
            serve=arr[front];
            front=rear=-1;
            System.out.println("Your order "+ serve +" served.");
        }
        else 
        {
            serve=arr[front];        //always in queue delete from first (first in first out)
            front=(front+1)%N;
            System.out.println("Your order "+ serve +" served.");
        }
        
    }
    
    void display()
    {
        if(front==-1 && rear==-1)
        {
            System.out.println("No orders for display in Queue Currently");
        }
        else{
        temp=front;
        while(temp!=rear)
        {
            System.out.println(" "+arr[temp]);
            temp=(temp+1)%N;
        }
         System.out.println(" " + arr[temp]);
        }
    }
     void isFull()
    {
        if((rear+1)%N==front)
        {
            System.out.println("Queue is full");
           
        }
        else{
            System.out.println("Queue is Not full");
        }
    }
    void isEmpty()
    {
        if(front==-1 && rear==-1)
        {
             System.out.println("Queue is Empty");
        }
        else{
            System.out.println("Queue is Not Empty");
        }
    }
}
public class Main
{
	public static void main(String[] args) {
	    int choice=1;
	    int data;
        pizza p=new pizza();
        
        Scanner sc=new Scanner(System.in);
        do{
            
            System.out.println("-----MENU-----");
            System.out.println("1.Place An Order");
            System.out.println("2.Serve An Order");
            System.out.println("3.Display Orders");
            System.out.println("4.Check if Queue is full?");
            System.out.println("5.Check if Queue is Empty?");
            System.out.println("0.Exit");
            System.out.println("Enter Choice: ");
            choice=sc.nextInt();
            
            switch(choice)
            {
                case 1:
                    System.out.println("Enter order: ");
                    data=sc.nextInt();
                    p.enqueue(data);
                    break;
                case 2:p.serveOrder();
                    break;
                case 3:p.display();
                     break;
                case 4:p.isFull();
                     break;
                case 5:p.isEmpty();
                     break;
                default:
                    System.out.println("Invalid Option");
            }
        }while(choice!=0);
	}
}
