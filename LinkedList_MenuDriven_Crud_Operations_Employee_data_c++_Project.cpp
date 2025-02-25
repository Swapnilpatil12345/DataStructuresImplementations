
import java.util.*;
class employee{
    String empid;
    String name;
    String role;
    String salary;
    employee next=null;

    employee(String empid,String name,String role,String salary)
    {
        this.empid=empid;
        this.name=name;
        this.role=role;
        this.salary=salary;
    }


    public static void display(employee head)
    {
        employee temp=head;
        while(temp!=null)
        {
            System.out.println(temp.empid+" "+temp.name+" "+temp.role+" "+temp.salary);
            System.out.println();
            temp=temp.next;
        }
    }
    public static employee insertAtEnd(employee head)
    {

        Scanner sc1 = new Scanner(System.in);
        System.out.println("Enter Employee ID: ");
        String empid=sc1.nextLine();
        System.out.println("Enter Name: ");
        String name=sc1.nextLine();
        System.out.println("Enter Designation/Role: ");
        String role=sc1.nextLine();
        System.out.println("Enter Salary: ");
        String salary=sc1.nextLine();

        employee newnode=new employee(empid,name,role,salary);

        employee temp=null;
        if(head==null)
        {
            head=newnode;
        }
        else
        {
            temp=head;
            while(temp.next!=null)
            {
                temp=temp.next;
            }
            temp.next=newnode;
        }
        return head;
    }
    public static void modify(employee head)
    {
        System.out.println("Enter the id you want to modify: ");
        Scanner sc7=new Scanner(System.in);
        String id=sc7.next();
        employee temp;
        temp=head;
        boolean found=false;
        while(temp!=null)
        {
            if(temp.empid.equals(id))
            {
                System.out.println(id + " ID Found with name " + temp.name);
                System.out.println("Enter Modifications: ");
                Scanner sc8=new Scanner(System.in);
                
                System.out.println("Enter Name: ");
                temp.name=sc8.nextLine();
                
                System.out.println("Enter Designation/Role: ");
                temp.role=sc8.nextLine();
                
                System.out.println("Enter Salary: ");
                temp.salary=sc8.nextLine();
                
                found=true;
                break;
            }
            else{
                temp=temp.next;
            }
        }
        if(!found)
        {
            System.out.println("Id not found");
        }
    }
    
    public static void search(employee head)
    {
        System.out.println("Enter the id you want to search: ");
        Scanner sc6=new Scanner(System.in);
        String id=sc6.next();
        employee temp;
        temp=head;
        boolean found=false;
        while(temp!=null)
        {
            if(temp.empid.equals(id))
            {
                System.out.println(id + " ID Found with name " + temp.name);
                
                found=true;
                break;
            }
            else{
                temp=temp.next;
            }
        }
        if(!found)
        {
            System.out.println("Id not found");
        }
    }
    
    public static void deleteEmp(employee head)
    {
        System.out.println("Enter the id you want to Delete: ");
        Scanner sc5=new Scanner(System.in);
        String id=sc5.next();
        employee temp,front;
        front=head;
        temp=head;
        boolean found=false;
        while(front!=null)
        {
           
            if(front.empid.equals(id))
            {
                
                System.out.println(id + " ID Successfully deleted with name " + front.name);
                
                temp.next=front.next;
                front.next=null;
                found=true;
                break;
            }
            else{
                temp=front;
                front=front.next;
            }
        }
        if(!found)
        {
            System.out.println("Id to be deleted is not found");
        }
    }
}
public class Main
{
    public static void main(String[] args) {
        employee head;
        head=null;
        int choice;
        Scanner sc3=new Scanner(System.in);
        do{
            System.out.println("----------------MENU------------------\n1.Insertion 2.Display 3.Search 4.Deletion 5.Modify");
            choice=sc3.nextInt();
            
            switch(choice)
            {
                case 1:head=employee.insertAtEnd(head);
                    break;
                case 2:employee.display(head);
                    break;
                case 3:employee.search(head);
                    break;
                case 4:employee.deleteEmp(head);
                    break;
                case 5:employee.modify(head);
                    break;
                default:
            }
        }while(choice!=0);

    }
}
