import java.util.concurrent.Semaphore;

class FooBar {
    private int n;
    private Semaphore fooSem = new Semaphore(1); // foo starts first
    private Semaphore barSem = new Semaphore(0);

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            fooSem.acquire();
            printFoo.run();   // prints "foo"
            barSem.release();
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            barSem.acquire();
            printBar.run();   // prints "bar"
            fooSem.release();
        }
    }
}
