public class Ticket {

	private String event;
	private String userName;
	private int ticketNumber;
	private double cost;

	/**
	 * 
	 * @param event
	 * @param username
	 * @param ticketNumber
	 * @param cost
	 */
	public Ticket(String event, String username, int ticketNumber, double cost) {
		throw new UnsupportedOperationException();
	}

	public String getEvent() {
		return this.event;
	}

	/**
	 * 
	 * @param event
	 */
	public void setEvent(String event) {
		this.event = event;
	}

	public String getUsername() {
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param username
	 */
	public void setUsername(String username) {
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