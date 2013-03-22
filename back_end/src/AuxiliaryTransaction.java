public class AuxiliaryTransaction extends Entry {

	private string username;
	private double credit;
	private string accountType;

	/**
	 * 
	 * @param type
	 * @param username
	 * @param credit
	 * @param accountType
	 */
	public AuxiliaryTransaction(int type, string username, double credit, string accountType) {
		throw new UnsupportedOperationException();
	}

	public string getUsername() {
		return this.username;
	}

	/**
	 * 
	 * @param username
	 */
	public void setUsername(string username) {
		this.username = username;
	}

	public double getCredit() {
		return this.credit;
	}

	/**
	 * 
	 * @param credit
	 */
	public void setCredit(double credit) {
		this.credit = credit;
	}

	public string getAccountType() {
		return this.accountType;
	}

	/**
	 * 
	 * @param accountType
	 */
	public void setAccountType(string accountType) {
		this.accountType = accountType;
	}

	public string getDTFLine() {
		throw new UnsupportedOperationException();
	}

}