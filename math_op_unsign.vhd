library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.float_pkg.all;
use ieee.fixed_pkg.all;

entity math_op_unsign is
  port ( X, Y : in ufixed(4 downto -2);
         Z    : out sfixed(8 downto -2) );
end entity math_op_unsign;


architecture behave of math_op_unsign is
  signal X_tmp, Y_tmp : ufixed(4 downto -2);
  signal Z_tmp        : sfixed(11 downto -2);

  begin
    X_tmp <= resize(X, X_tmp);
    Y_tmp <= resize(Y, Y_tmp);

    Z_tmp <= to_sfixed(5 * X_tmp) - to_sfixed(Y_tmp);
    Z <= resize(Z_tmp, 8, -2);
end architecture behave;
