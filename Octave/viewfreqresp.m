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

  w = linspace(0, sample_freq/2, 512)./sample_freq; # eje x
  H = zeros(1, length(w)); # inicializa el vector de respuesta
  angles = zeros(1, length(w));

  numerator = polyval(flip(b), exp(-1i * w));
  denominator = polyval(flip(a), exp(-1i * w));

  H = numerator ./ denominator;

  for k= 1:length(H)
    if angle(H(k)) > 0
      angles(k) = angle(H(k))* 180/pi - 360;
    else
      angles(k) = angle(H(k))* 180/pi;
    endif
  endfor

  figure(1)
  subplot(2, 1, 1);
  plot(w.*sample_freq, abs(H));
  axis([0, sample_freq/2, -20, 5])
  title('Respuesta en magnitud');
  xlabel('F(Hz)');
  ylabel('|H(F)|[dB]');

  subplot(2, 1, 2);
  plot(w.*sample_freq, angles);
  axis([0, sample_freq/2, -360, 0])
  title('Respuesta de fase');
  xlabel('F');
  ylabel('\angle H(F) [\deg]');

  figure(2)
  freqz(b,a,[],sample_freq)

endfunction
