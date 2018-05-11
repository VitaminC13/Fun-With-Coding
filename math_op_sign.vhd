library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.float_pkg.all;
use ieee.fixed_pkg.all;

entity math_op_sign is
  port ( X, Y : in sfixed(4 downto -2);
         Z    : out sfixed(9 downto -2) );
end entity math_op_sign;

architecture behave of math_op_sign is
  signal X_tmp, Y_tmp : sfixed(9 downto -2);
  signal Z_tmp        : sfixed(20 downto -2);
  begin
    X_tmp <= resize(X, X_tmp);
    Y_tmp <= resize(Y, Y_tmp);

    Z_tmp <= (5 * X_tmp) -  Y_tmp;

    Z <= resize(Z_tmp, 9, -2);
end architecture behave;
