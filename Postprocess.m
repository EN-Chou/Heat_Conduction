m_grid=xlsread('result.csv', 'A1:AO41');
%m_grid=xlsread('result.csv', 'A1:CC81');
%m_grid=xlsread('result.csv', 'A1:FE161');
%m_grid=xlsread('result.csv', 'A1:IG241');

imagesc(m_grid);
axis square