using System;
					
public class Program
{
	public static void Main()
	{
		
		int singleBurgers = Convert.ToInt32(Console.ReadLine());
		int doubleBurgers = Convert.ToInt32(Console.ReadLine());
		int deckers = Convert.ToInt32(Console.ReadLine());
		int patties = 0;
		int cheeses = 0;
		int buns = 0;
		
		patties += singleBurgers;
		cheeses += singleBurgers;
		buns += singleBurgers * 2;
		
		patties += doubleBurgers * 2;
		cheeses += doubleBurgers * 2;
		buns += doubleBurgers * 2;
		
		if ((deckers + 1) <= buns && deckers <= cheeses && deckers <= patties) {
			Console.WriteLine("yay");
		}
		else {
			Console.WriteLine("nay");
		}
	}

	
}

