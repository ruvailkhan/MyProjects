
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY tb_counter_4bit IS
END tb_counter_4bit;
 
ARCHITECTURE behavior OF tb_counter_4bit IS 

    COMPONENT counter_4bit
    PORT(
         clk : IN  std_logic;
         rst : IN  std_logic;
         cnt : OUT  std_logic_vector(3 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal clk : std_logic := '0';
   signal rst : std_logic := '0';

 	--Outputs
   signal cnt : std_logic_vector(3 downto 0);

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: counter_4bit PORT MAP (
          clk => clk,
          rst => rst,
          cnt => cnt
        );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
	
	rst<='1';
	wait for 100 ns;
	
	rst<='0';
	wait for 900 ns;



   end process;

END;
