public class Ticket {

	private string event;
	private string userName;
	private int ticketNumber;
	private double cost;

	/**
	 * 
	 * @param event
	 * @param username
	 * @param ticketNumber
	 * @param cost
	 */
	public Ticket(string event, string username, int ticketNumber, double cost) {
		throw new UnsupportedOperationException();
	}

	public string getEvent() {
		return this.event;
	}

	/**
	 * 
	 * @param event
	 */
	public void setEvent(string event) {
		this.event = event;
	}

	public string getUsername() {
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param username
	 */
	public void setUsername(string username) {
		throw new UnsupportedOperationException();
	}

	public int getTicketNumber() {
		return this.ticketNumber;
	}

	/**
	 * 
	 * @param ticketNumber
	 */
	public void setTicketNumber(int ticketNumber) {
		this.ticketNumber = ticketNumber;
	}

	/**
	 * 
	 * @param ticketNumber
	 */
	public void decreaseTicketNumber(int ticketNumber) {
		throw new UnsupportedOperationException();
	}

	public double getCost() {
		return this.cost;
	}

	/**
	 * 
	 * @param cost
	 */
	public void setCost(double cost) {
		this.cost = cost;
	}

}