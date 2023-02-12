library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity D_f_f is
port (
clk: in std_logic;
rst: in std_logic;
D: in std_logic;
Q,Qn: out std_logic);
end entity;

architecture D_f_f_arch of D_f_f is

begin
D_flip_flop : process(clk,rst)
begin
if(rst='1') then
Q<='0'; Qn<='1';
elsif(clk'event and clk='1') then
Q<=D; Qn<=not D;
end if;
end process D_flip_flop;
end architecture;
