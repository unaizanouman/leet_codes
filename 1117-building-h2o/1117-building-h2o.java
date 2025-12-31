import java.util.concurrent.Semaphore;

class H2O {
    private Semaphore hydrogen = new Semaphore(2);
    private Semaphore oxygen = new Semaphore(0);

    public H2O() {}

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        hydrogen.acquire();          // allow only 2 hydrogens
        releaseHydrogen.run();       // print "H"
        oxygen.release();            // signal oxygen
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        oxygen.acquire(2);           // wait for 2 hydrogens
        releaseOxygen.run();         // print "O"
        hydrogen.release(2);         // reset for next molecule
    }
}
