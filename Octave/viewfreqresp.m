## Copyright (C) 2024 Juan Pablo Rodriguez
##
## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <https://www.gnu.org/licenses/>.

## -*- texinfo -*-
## @deftypefn {} {@var{retval} =} viewfreqresp (@var{input1}, @var{input2})
##
## @seealso{}
## @end deftypefn

## Author: Juan Pablo Rodriguez <juanpablorodriguez@Juans-Air>
## Created: 2024-09-21

function retval = viewfreqresp (filename, sample_freq)
  Data = load(filename, "SOS");
  [b,a] = sos2tf(Data.SOS);

  w = linspace(0, sample_freq/2, 512); # eje x
  w_1 = 1./w; #
  H = zeros(1, length(w)); # inicializa el vector de respuesta
  numerator = polyval(flip(b), w_1);
  denominator = polyval(flip(a), w_1);
  H = numerator./denominator;

  subplot(2, 1, 1);
  plot(w, 20*log10(abs(H)));  % Magnitude in dB
  title('Respuesta en magnitud');
  xlabel('F');
  ylabel('|H(F)|[dB]');

  subplot(2, 1, 2);
  plot(w, angle(H));
  title('Respuesta de fase');
  xlabel('F');
  ylabel('\angle H(F) [\deg]');



endfunction
