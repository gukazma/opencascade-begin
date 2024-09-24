#include "OCCWidget.h"

#include "Aspect_DisplayConnection.hxx"
#include "OpenGl_GraphicDriver.hxx"
#include "WNT_Window.hxx"

OCCWidget::OCCWidget(QWidget* parent)
    : QWidget{ parent }
{
    // ֱ�ӻ�������Ļ��
    this->setAttribute(Qt::WA_PaintOnScreen);
    // ����������ʾ�豸
    Handle(Aspect_DisplayConnection) m_Aspect_DisplayConnect = new Aspect_DisplayConnection();
    // ����3D�ӿڶ���ͼ������
    Handle(OpenGl_GraphicDriver) driver = new OpenGl_GraphicDriver(m_Aspect_DisplayConnect);
    // ����3D�鿴�����󣬲�ָ��ͼ������
    m_viewer = new V3d_Viewer(driver);
    // �������������Ķ��󣬹�����3D�鿴��
    m_context = new AIS_InteractiveContext(m_viewer);
    // ������ͼ����������3D�鿴��
    m_view = m_viewer->CreateView();
    // ��ȡ���ھ��������WNT_Window
    WId window_handle = (WId)winId();
    Handle(WNT_Window) wind = new WNT_Window((Aspect_Handle)window_handle);
    // ������ͼ����
    m_view->SetWindow(wind);
    if (!wind->IsMapped()) wind->Map();
}

QPaintEngine* OCCWidget::paintEngine() const
{
    return nullptr;
}

void OCCWidget::paintEvent(QPaintEvent* /*theEvent*/)
{
    m_view->Redraw();
}

void OCCWidget::resizeEvent(QResizeEvent* /*theEvent*/)
{
    if (!m_view.IsNull())
    {
        m_view->MustBeResized();
    }
}
