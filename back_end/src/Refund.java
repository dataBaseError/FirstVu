public class Refund extends Entry {

    private String buyName;
    private String sellName;
    private double credit;

    /**
     * 
     * @param type
     * @param buyName
     * @param sellName
     * @param credit
     */
    public Refund(final int type, final String buyName, final String sellName, final double credit) {
        super(type);
        throw new UnsupportedOperationException();
    }

    public String getBuyName() {
        return this.buyName;
    }

    /**
     * 
     * @param buyName
     */
    public void setBuyName(final String buyName) {
        this.buyName = buyName;
    }

    public String getSellName() {
        return this.sellName;
    }

    /**
     * 
     * @param sellName
     */
    public void setSellName(final String sellName) {
        this.sellName = sellName;
    }

    public double getCredit() {
        return this.credit;
    }

    /**
     * 
     * @param credit
     */
    public void setCredit(final double credit) {
        this.credit = credit;
    }

    @Override
    public String getDTFLine() {
        throw new UnsupportedOperationException();
    }

}