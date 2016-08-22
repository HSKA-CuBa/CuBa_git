%15.8.2016, Michael Meindl
%Berechnet Ausgleichspolynom aus den Mittelwerte zu den Sollwerten und
%plottet Ergebnisse

rpm = [-3000 -2000 -1000 0 1000 2000 3000];
si_values = degtorad(rpm*6);

load('Messwerte\adc_values_rpm_-3000');
adc_values_rpm_m3000 = adc_values;
load('Messwerte\adc_values_rpm_-2000');
adc_values_rpm_m2000 = adc_values;
load('Messwerte\adc_values_rpm_-1000');
adc_values_rpm_m1000 = adc_values;
load('Messwerte\adc_values_rpm_0');
adc_values_rpm_0 = adc_values;
load('Messwerte\adc_values_rpm_1000');
adc_values_rpm_1000 = adc_values;
load('Messwerte\adc_values_rpm_2000');
adc_values_rpm_2000 = adc_values;
load('Messwerte\adc_values_rpm_3000');
adc_values_rpm_3000 = adc_values;

adc_mean_values = [mean(adc_values_rpm_m3000) mean(adc_values_rpm_m2000) ...
    mean(adc_values_rpm_m1000) mean(adc_values_rpm_0) mean(adc_values_rpm_1000) ...
    mean(adc_values_rpm_2000) mean(adc_values_rpm_3000)];

adc_polynom = fit(adc_mean_values', si_values', 'poly1');
adc_psi_d_values = adc_polynom.p1*adc_mean_values + adc_polynom.p2;
plot(si_values, si_values, si_values, adc_psi_d_values, si_values, si_values-adc_psi_d_values); grid;
xlabel('$\dot\psi$ [$\frac{rad}{s}$]', 'interpreter', 'latex');
ylabel('$\dot\psi$ [$\frac{rad}{s}$]', 'interpreter', 'latex');
legend('Sollwert', 'Polynomwert', 'Fehler', 'Location', 'northwest');
title('Umrechnung der ADC-Mittelwerte in Winkelgeschwindigkeiten');
print('Plots/ADC_mittelwert_polynom', '-depsc');