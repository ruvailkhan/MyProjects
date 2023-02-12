
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

	entity counter_4bit is
	port (
	clk: in std_logic;
	rst: in std_logic;
	cnt: out std_logic_vector(3 downto 0));
	end entity;

	architecture counter_4bit_arch of counter_4bit is

	component D_f_f
	port (
	clk: in std_logic;
	rst: in std_logic;
	D: in std_logic;
	Q,Qn: out std_logic);
	end component;

	signal Q_nxt,Q_cur,Qn_cur: std_logic_vector(3 downto 0);
	signal count: std_logic_vector(3 downto 0);

	begin

	DFF0: D_f_f port map(clk=>clk,rst=>rst,D=>Q_nxt(0),Q=>Q_cur(0),Qn=>Qn_cur(0));
	DFF1: D_f_f port map(clk=>clk,rst=>rst,D=>Q_nxt(1),Q=>Q_cur(1),Qn=>Qn_cur(1));
	DFF2: D_f_f port map(clk=>clk,rst=>rst,D=>Q_nxt(2),Q=>Q_cur(2),Qn=>Qn_cur(2));
	DFF3: D_f_f port map(clk=>clk,rst=>rst,D=>Q_nxt(3),Q=>Q_cur(3),Qn=>Qn_cur(3));

	Q_nxt<="0001" when (Q_cur="0000")else
			 "0010" when (Q_cur="0001")else
			 "0011" when (Q_cur="0010" )else
			 "0100" when (Q_cur="0011" )else
			 "0101" when (Q_cur="0100" )else
			 "0110" when (Q_cur="0101" )else
			 "0111" when (Q_cur="0110" )else
			 "1000" when (Q_cur="0111" )else
			 "1001" when (Q_cur="1000" )else
			 "1010" when (Q_cur="1001" )else
			 "1011" when (Q_cur="1010" )else
			 "1100" when (Q_cur="1011" )else
			 "1101" when (Q_cur="1100" )else
			 "1110" when (Q_cur="1101" )else
			 "1111" when (Q_cur="1110" )else
			 "0000" when (Q_cur="1111" );
	cnt<=Q_cur;

	end architecture;