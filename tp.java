import java.util.*

public class Main {
    public static void main (String argvil) throws CloneNotSupportedException {
        ArrayList<MyClass> l1 = newArrayList<MyClass>() ;
        ArrayList<MyClass> l3 = new ArrayList<MyClass>();
        ArrayList<MyClass> l2 = l1;
        Long seed = 1234567890;
        int size = 10;
        if(argv.length>0) size = Integer.value0f(argv[0]);
        Random rand = new Random (seed);
        for(int i = 0; i < size; i++) l1.add (new MyClass (rand.nextInt (400)+""));
        for(int i = 0; i < size; i++) l3. add (new MyClass (l1.get (size-i-1)));
        for(int i = 0; i < size; i++) {
            System.out.print(l1.get(i).getClass().getName()+":"+l1.get(i));
            System.out.print(l2.get(i).getClass().getName()+":"+l2.get(i));
            System.out.print(l3.get(i).getClass().getName()+":"+l3.get(i));
        }
        System.out.println();
    }
}
public class MyClass implements Cloneable {
    private Object data;
    private LoremIpsum loremIpsom = new LoremIpsum ();
    private static int toStringCallCount = 0;
    public MyClass (Object o) {
        data = 0;
    }
protected MyClass clone() throws CloneNotSupportedException {
    MyClass mc = (MyClass)super.clone() ;
    mc.data = new Object ();
    mc.data = data;
    return mc;
}
public String toString() {
    toStringCallCount++;
    return data.getClass().getSimpleName ()+":"+data+":"+
    loremIpsom.getWords(2,Integer.min(toStringCallCount,40))+":"
    }
}