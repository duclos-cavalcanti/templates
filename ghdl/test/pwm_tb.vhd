----------------------------------------------------------------------------------
-- Company:
-- Engineer: Daniel Duclos-Cavalcanti
-- 
-- Create Date: 10/06/2021 03:39:49 PM
-- Design Name: 
-- Module Name: Testbench - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity pwm_tb is
end pwm_tb;

architecture Behavioral of pwm_tb is
    component pwm
    generic (
        F_Pwm   :   integer := 200 * 10**3; -- !in Hz
        F_Clk   :   integer := 125 * 10**6; -- !in Hz
        Duty_Cycle : integer;
        T_Tot   :   time := 400 ns
    );
    port ( 
        clk : in std_logic;
        Start_Flag : in std_logic;
        Pwm_1 : out std_logic;
        Pwm_2 : out std_logic
    );
    end component;
    
    signal clk_sig : std_logic := '0';
    signal start_flag_sig : std_logic := '1';
    signal pwm_out_1_sig: std_logic := '1';
    signal pwm_out_2_sig: std_logic := '1';
begin
    clk_sig <= not clk_sig after 8 ns;

    UUT: pwm 
    generic map(
        25 * 10**6, -- F_Pwm
        125 * 10**6, -- F_Clk
        3, -- Duty Cycle
        0 ns -- T_Tot
    )
    port map (
        clk=> clk_sig, Start_Flag => start_flag_sig, Pwm_1 => pwm_out_1_sig, Pwm_2 => pwm_out_2_sig
    );
    
    process
    begin
        wait for 1 sec;
    end process;

end Behavioral;
