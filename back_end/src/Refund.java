public class Refund extends Entry {

	private string buyName;
	private string sellName;
	private double credit;

	/**
	 * 
	 * @param type
	 * @param buyName
	 * @param sellName
	 * @param credit
	 */
	public Refund(int type, string buyName, string sellName, double credit) {
		throw new UnsupportedOperationException();
	}

	public string getBuyName() {
		return this.buyName;
	}

	/**
	 * 
	 * @param buyName
	 */
	public void setBuyName(string buyName) {
		this.buyName = buyName;
	}

	public string getSellName() {
		return this.sellName;
	}

	/**
	 * 
	 * @param sellName
	 */
	public void setSellName(string sellName) {
		this.sellName = sellName;
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

	public string getDTFLine() {
		throw new UnsupportedOperationException();
	}

}