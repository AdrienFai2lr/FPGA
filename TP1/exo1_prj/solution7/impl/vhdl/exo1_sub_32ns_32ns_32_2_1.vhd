-- ==============================================================
-- Generated by Vitis HLS v2023.2
-- Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
-- ==============================================================
-- 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
-- 
-- 
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.NUMERIC_STD.all;

entity exo1_sub_32ns_32ns_32_2_1 is
    generic (
        ID          : INTEGER := 1;
        NUM_STAGE   : INTEGER := 2;
        din0_WIDTH  : INTEGER := 32;
        din1_WIDTH  : INTEGER := 32;
        dout_WIDTH  : INTEGER := 32);
    port (
        clk : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        ce : IN STD_LOGIC;
        din0 : IN STD_LOGIC_VECTOR(din0_WIDTH - 1 DOWNTO 0);
        din1 : IN STD_LOGIC_VECTOR(din1_WIDTH - 1 DOWNTO 0);
        dout : OUT STD_LOGIC_VECTOR(dout_WIDTH - 1 DOWNTO 0));
end entity;
--     

architecture behav of exo1_sub_32ns_32ns_32_2_1 is
  component exo1_sub_32ns_32ns_32_2_1_comb_adder is 
    generic(N : natural := 32);
    port (
      din0    : IN  STD_LOGIC_VECTOR (N-1 downto 0);
      din1    : IN  STD_LOGIC_VECTOR (N-1 downto 0);
      cin  : IN  STD_LOGIC_VECTOR (0 downto 0);
      dout    : OUT STD_LOGIC_VECTOR (N-1 downto 0);
      cout : OUT STD_LOGIC_VECTOR (0 downto 0));
  end component;

    signal s_tmp : std_logic_vector(31 downto 0);
-- 

-- ---- register and wire type variables list here ----

-- wire for the primary inputs
  signal ain_s0 : STD_LOGIC_VECTOR(31 downto 0);
  signal bin_s0 : STD_LOGIC_VECTOR(31 downto 0);

-- 
--  
-- Stage 1 signals
  signal  fas_s1     : STD_LOGIC_VECTOR(16 -1 downto 0);
  signal  facout_s1  : STD_LOGIC_VECTOR(0 downto 0);
-- 
  signal  ain_s1     : STD_LOGIC_VECTOR(16 - 1 downto 0);
  signal  bin_s1     : STD_LOGIC_VECTOR(16 - 1 downto 0);
  signal  sum_s1     : STD_LOGIC_VECTOR(16 - 1 downto 0);
  signal  carry_s1   : STD_LOGIC_VECTOR(0 downto 0);
-- 

--  
-- Stage 2 signals
  signal  fas_s2     : STD_LOGIC_VECTOR(16 -1 downto 0);
  signal  facout_s2  : STD_LOGIC_VECTOR(0 downto 0);
-- 

-- 
begin

ain_s0 <= std_logic_vector(resize(unsigned(din0), 32));
-- 
bin_s0 <= not std_logic_vector(resize(unsigned(din1), 32));
-- 

-- This AddSub module have totally 2 stages. For each stage the adder's width are:
-- [16,16]

--  
--  
-- 
--  
--  
-- 

u1 : exo1_sub_32ns_32ns_32_2_1_comb_adder
  generic map
    ( N => 16 )
  port map
    (din0    => ain_s0(16 - 1 downto 0),
     din1    => bin_s0(16 - 1 downto 0),
     cin  => "1",
     dout    => fas_s1,
     cout => facout_s1);

-- Stage 1 logic
-- 
process (clk) begin
  if (clk'event and clk = '1') then
    if (ce = '1') then
        sum_s1   <= fas_s1;
        carry_s1 <= facout_s1;
    end if;
  end if;
end process;

process (clk) begin
  if (clk'event and clk = '1') then
    if (ce = '1') then
        ain_s1 <= ain_s0(32 - 1 downto 16);
    end if;
  end if;
end process;

process (clk) begin
  if (clk'event and clk = '1') then
    if (ce = '1') then
        bin_s1 <= bin_s0(32 - 1 downto 16);
    end if;
  end if;
end process;
--  
--  
-- 
-- 

u2 : exo1_sub_32ns_32ns_32_2_1_comb_adder
  generic map
    ( N => 16 )
  port map
    (din0    => ain_s1(16 - 1 downto 0),
     din1    => bin_s1(16 - 1 downto 0),
     cin  => carry_s1,
     dout    => fas_s2,
     cout => facout_s2);

-- Stage 2 logic
-- 
s_tmp <= fas_s2 & sum_s1;
dout <= std_logic_vector(s_tmp);
--  
-- 

end architecture;

-- small adder
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.NUMERIC_STD.all;

entity exo1_sub_32ns_32ns_32_2_1_comb_adder is
  generic(N : natural := 32);
  port (
      din0    : IN  STD_LOGIC_VECTOR (N-1 downto 0);
      din1    : IN  STD_LOGIC_VECTOR (N-1 downto 0);
      cin  : IN  STD_LOGIC_VECTOR (0 downto 0);
      dout    : OUT STD_LOGIC_VECTOR (N-1 downto 0);
      cout : OUT STD_LOGIC_VECTOR (0 downto 0));
end;

architecture behav of exo1_sub_32ns_32ns_32_2_1_comb_adder is
    signal tmp : STD_LOGIC_VECTOR (N downto 0);
begin

  tmp  <= std_logic_vector(resize(unsigned(din0),N+1) + unsigned(din1) + unsigned(cin));
  dout    <= tmp(N-1 downto 0 );
  cout <= tmp(N downto N);

end architecture;
-- 