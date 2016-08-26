%15.8.2016, Michael Meindl
%Terminate-Skript fuer Versuch 3, Speichert die ADC-Werte und RPM-Wert

rpm_factor = -140000;
rpm_vec    = [-3000 -2000 -1000 0 1000 2000 3000];
T_vec      = rpm_vec/rpm_factor;

t = ADC_TStruct.time(502:1000);
adc_values = ADC_TStruct.signals(1).values(502:1000);
adc_mean   = mean(adc_values);
mean_arr   = ones(size(adc_values))*adc_mean;

figure;
plot(t, adc_values, t, mean_arr); grid;
xlabel('Zeit [s]'); ylabel('ADC-Werte []');
legend('ADC-Werte', 'Mittelwert');
title(strcat('ADC-Werte bei RPM = ', num2str(rpm)));
print(strcat('Plots/adc_values_rpm_', num2str(rpm)), '-depsc');

savefileName = strcat('Messwerte/adc_values_rpm_', num2str(rpm));
save(savefileName, 't', 'adc_values');