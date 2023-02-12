
library IEEE;
use IEEE.std_logic_1164.all;

entity combine is
port(
  a: in std_logic;
  b: in std_logic;
  c: in std_logic;
  d: in std_logic;
  q: out std_logic);
end combine;

architecture Behavioral of combine is
begin
process(a, b,c,d) 
begin
if(a='0' and b='0' and c='0' and d='0') then
q<='0';
else if(a='0' and b='0' and c='0' and d='1') then
q<='0';
else if(a='0' and b='0' and c='1' and d='0') then
q<='1';
else if(a='0' and b='0' and c='1' and d='1') then
q<='1';
else if(a='0' and b='1' and c='0' and d='0') then
q<='1';
else if(a='0' and b='1' and c='0' and d='1') then
q<='1';
else if(a='0' and b='1' and c='1' and d='0') then
q<='1';
else if(a='0' and b='1' and c='1' and d='1') then
q<='0';
else if(a='1' and b='0' and c='0' and d='0') then
q<='1';
else if(a='1' and b='0' and c='0' and d='1') then
q<='0';
else if(a='1' and b='0' and c='1' and d='0') then
q<='1';
else if(a='1' and b='0' and c='1' and d='1') then
q<='0';
else if(a='1' and b='1' and c='0' and d='0') then
q<='1';
else if(a='1' and b='1' and c='0' and d='1') then
q<='1';
else if(a='1' and b='1' and c='1' and d='0') then
q<='0';
else if(a='1' and b='1' and c='1' and d='1') then
q<='1';
end if;
end if;
end if;
end if;
end if;
end if;
end if;
end if;
end if;
end if;
end if;
end if;
end if;
end if;
end if;
end if;




end process;
end Behavioral;
