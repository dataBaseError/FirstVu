public class EventTransaction extends Entry {

	private string eventName;
	private string sellName;
	private double price;
	private int numTickets;

	/**
	 * 
	 * @param type
	 * @param eventName
	 * @param sellName
	 * @param price
	 * @param numTickets
	 */
	public EventTransaction(int type, string eventName, string sellName, double price, int numTickets) {
		throw new UnsupportedOperationException();
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

	public string getEventName() {
		return this.eventName;
	}

	/**
	 * 
	 * @param eventName
	 */
	public void setEventName(string eventName) {
		this.eventName = eventName;
	}

	public double getPrice() {
		return this.price;
	}

	/**
	 * 
	 * @param price
	 */
	public void setPrice(double price) {
		this.price = price;
	}

	public int getNumTickets() {
		return this.numTickets;
	}

	/**
	 * 
	 * @param numTickets
	 */
	public void setNumTickets(int numTickets) {
		this.numTickets = numTickets;
	}

	public string getDTFLine() {
		throw new UnsupportedOperationException();
	}

}