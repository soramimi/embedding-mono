
using System;
using System.Runtime.InteropServices;

namespace Test {
	public class Class1 {

		[DllImport("lib")]
		static extern int sub(int a, int b);

		public static int Add(int a, int b, int c)
		{
			
			return sub(a + b, c);
		}

	}
}


