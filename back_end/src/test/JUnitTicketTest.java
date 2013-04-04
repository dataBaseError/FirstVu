package test;
import static org.junit.Assert.*;

import main.Ticket;

import org.junit.Test;


public class JUnitTicketTest {

	@Test
	public void test() {
		testGetType();
		testGetUsernames();
		testGetUsernames();
		testGetTicketNumber();
		testDecreaseTicketNumber();
		testGetCost();
		testGetTicketEntry();
	}

	public void testGetType() {
		
		Ticket testTicket = new Ticket("event", "seller", 1, 1.0);
		assertSame(testTicket.getEvent(), "event");
	}
	
	public void testGetUsernames() {
		
		Ticket testTicket = new Ticket("event", "seller", 1, 1.0);
		assertSame(testTicket.getUsername(), "seller");
	}
	
	public void testGetTicketNumber() {
		
		Ticket testTicket = new Ticket("event", "seller", 1, 1.0);
		assertTrue(testTicket.getTicketNumber() == 1);
	}
	
	public void testDecreaseTicketNumber() {
		
		Ticket testTicket = new Ticket("event", "seller", 1, 1.0);
		testTicket.decreaseTicketNumber(1);
		
		assertTrue(testTicket.getTicketNumber() == 0);
	}
	
	public void testGetCost() {
		
		Ticket testTicket = new Ticket("event", "seller", 1, 1.0);
		
		
		assertTrue(testTicket.getCost() == 1.0);
	}
	
	public void testGetTicketEntry() {
		
		Ticket testTicket = new Ticket("event", "seller", 1, 1.0);
		
		System.out.println(testTicket.getTicketEntry() + "\n" +("event               seller          001 001.00"));
		assertTrue(testTicket.getTicketEntry().equals("event               seller          001 001.00"));
	}
}
