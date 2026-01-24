
public class Solution {
    public int GetSum(int a, int b) {

        if (a < 0 || b < 0) {
            
        }

        string a_binary = Convert.ToString(a, 2);
        string b_binary = Convert.ToString(b, 2);

        StringBuilder result = new StringBuilder();

        bool carryOver = false;
        int a_pointer = a_binary.Length - 1;
        int b_pointer = b_binary.Length - 1;

        while (0 <= a_pointer && 0 <= b_pointer) {
			if (Int32.Parse(a_binary[a_pointer].ToString()) == 1 && Int32.Parse(b_binary[b_pointer].ToString()) == 1) {
				if (carryOver) {
					result.Append(1);
				}
				else {
					result.Append(0);
					carryOver = true;
				}
				a_pointer--;
				b_pointer--;
				continue;
			}
            if (Int32.Parse(a_binary[a_pointer].ToString()) == 0 && Int32.Parse(b_binary[b_pointer].ToString()) == 0) {
                if (carryOver) {
                    result.Append(1);
                    carryOver = false;
                    a_pointer--;
                    b_pointer--;
                    continue;
                }
                else {
                    result.Append(0);
                    a_pointer--;
                    b_pointer--;
                    continue;
                }
            }

            if (Int32.Parse(a_binary[a_pointer].ToString()) == 0 && Int32.Parse(b_binary[b_pointer].ToString()) == 1
                || Int32.Parse(a_binary[a_pointer].ToString()) == 1 && Int32.Parse(b_binary[b_pointer].ToString()) == 0) 
            {
                if (carryOver) {
                    result.Append(0);
                    a_pointer--;
                    b_pointer--;
                    continue;
                }
                else {
                    result.Append(1);
                    a_pointer--;
                    b_pointer--;
                    continue;
                }
            }

        }
		
		// Copy over any remaining numbers
		while (0 <= a_pointer) {
			if (carryOver) {
				// Handle additional carry-overs
				if (a_binary[a_pointer] == '1') {
					result.Append(0);
					carryOver = true;
				} else {
					result.Append(1);
					carryOver = false;
				}
			} else {
				result.Append(a_binary[a_pointer]);
			}
			a_pointer--;
		}

		while (0 <= b_pointer) {
			if (carryOver) {
				// Handle additional carry-overs
				if (b_binary[b_pointer] == '1') {
					result.Append(0);
					carryOver = true;
				} else {
					result.Append(1);
					carryOver = false;
				}
			} else {
				result.Append(b_binary[b_pointer]);
			}
			b_pointer--;
		}

		// Append the final carry-over if needed
		if (carryOver) {
			result.Append(1);
		}
		
		return Convert.ToInt32(ReverseString(result.ToString()), 2);


    }
	
	public string ReverseString(string s)
    {
        char[] arr = s.ToCharArray();
        Array.Reverse(arr);
        return new string(arr);
    }
}
