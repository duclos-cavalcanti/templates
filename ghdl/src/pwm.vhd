----------------------------------------------------------------------------------
-- Company:
-- Engineer: Daniel Duclos-Cavalcanti
-- 
-- Create Date: 10/06/2021 12:29:49 PM
-- Design Name: 
-- Module Name: PulseWidthModulator - Behavioral
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
use IEEE.NUMERIC_STD.ALL;

entity pwm is
    generic (
        F_Pwm   :   integer := 200 * 10**3; -- !in Hz
        F_Clk   :   integer := 125 * 10**6; -- !in Hz
        Duty_Cycle : integer; -- !Number of Clock Ticks until PWM goes low
        T_Tot   :   time := 400 ns -- !in Nanoseconds
    );
    port ( 
        clk : in std_logic;
        Start_Flag : in std_logic;
        Pwm_1 : out std_logic;
        Pwm_2 : out std_logic
    );
end pwm;

architecture RTL of pwm is
    constant c_pwm_period : integer := F_Clk / F_Pwm; -- number of necessary clock ticks to equal one PWM period
    constant c_on_period : integer := Duty_Cycle;
    constant c_off_period : integer := c_pwm_period - c_on_period; -- bla bla bla
    
    signal pwm_state : std_logic := '1';
    signal pwm_out : std_logic := '1';
    signal sel_state : std_logic := '0';
    signal period_end : std_logic := '0';
    
    shared variable cnt_max : natural := c_on_period;
begin
    Select_Period : process(sel_state)
    begin
        case sel_state is
            when '0' =>
                cnt_max := c_on_period;
            
            when '1' =>
                cnt_max := c_off_period;
            
            when others =>
        end case;            
    end process;
    
    
    Count_Clk : process(clk)
    variable cnt : integer range 0 to c_pwm_period := 0;
    begin
        if rising_edge(clk) then
            if start_flag = '1' then
                if cnt < cnt_max - 1 then -- counting up to the period end
                    cnt := cnt + 1;
                else -- reached period end
                    cnt := 0;
                    period_end <= not period_end;
                    sel_state <= not sel_state; -- triggers period selection
                    pwm_state <= not pwm_state;
                end if;
            else
                if period_end = '1' then -- only reset when at Period End
                    cnt := 0;
                    sel_state <= '0';
                end if;
            end if;   
         end if;   
    end process Count_Clk;
    
    Pwm_Delay : process
    begin
        wait on pwm_state; -- waits on changes to pwm_state
        wait for T_Tot; -- waits for instantiated totzeit
        pwm_out <= pwm_state;
    end process Pwm_Delay;

    Pwm_Output : process(clk, pwm_out)
    begin
        if rising_edge(clk) or rising_edge(pwm_out) or falling_edge(pwm_out) then
            if start_flag = '1' then
                Pwm_1 <= pwm_out; -- takes the signal value from pwm_out
                Pwm_2 <= pwm_out; -- takes the signal value from pwm_out   
            else
                if period_end = '1' then -- only reset at Period End
                    Pwm_1 <= '0';
                    Pwm_2 <= '0';
                end if;
            end if;
        end if;
    end process Pwm_Output;

end RTL;
