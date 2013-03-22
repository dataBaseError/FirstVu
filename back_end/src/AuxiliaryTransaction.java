public class AuxiliaryTransaction extends Entry {

    private String username;
    private double credit;
    private String accountType;

    /**
     * 
     * @param type
     * @param username
     * @param credit
     * @param accountType
     */
    public AuxiliaryTransaction(final int type, final String username, final double credit, final String accountType) {
        super(type);
        throw new UnsupportedOperationException();
    }

    public String getUsername() {
        return this.username;
    }

    /**
     * 
     * @param username
     */
    public void setUsername(final String username) {
        this.username = username;
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

    public String getAccountType() {
        return this.accountType;
    }

    /**
     * 
     * @param accountType
     */
    public void setAccountType(final String accountType) {
        this.accountType = accountType;
    }

    @Override
    public String getDTFLine() {
        throw new UnsupportedOperationException();
    }

}