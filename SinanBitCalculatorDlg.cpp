
// SinanBitCalculatorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SinanBitCalculator.h"
#include "SinanBitCalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSinanBitCalculatorDlg dialog



CSinanBitCalculatorDlg::CSinanBitCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSinanBitCalculatorDlg::IDD, pParent)
	, radioVariable(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSinanBitCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, checkVariable);
	DDX_Control(pDX, IDC_EDIT3, bitshiftingvariable);
	DDX_Control(pDX, IDC_EDIT1, input1);
	DDX_Control(pDX, IDC_EDIT2, input2);
	DDX_Radio(pDX, IDC_RADIO1, radioVariable);
	DDX_Control(pDX, IDC_COMBO1, comboBoxNew);
	DDX_Control(pDX, IDC_LIST1, listVariable);
}

BEGIN_MESSAGE_MAP(CSinanBitCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CSinanBitCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO1, &CSinanBitCalculatorDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CSinanBitCalculatorDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CSinanBitCalculatorDlg::OnBnClickedRadio3)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CSinanBitCalculatorDlg::OnCbnSelchangeCombo1)
	ON_EN_CHANGE(IDC_EDIT3, &CSinanBitCalculatorDlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_CHECK1, &CSinanBitCalculatorDlg::OnBnClickedCheck1)
	ON_LBN_SELCHANGE(IDC_LIST1, &CSinanBitCalculatorDlg::OnLbnSelchangeList1)
END_MESSAGE_MAP()


// CSinanBitCalculatorDlg message handlers

BOOL CSinanBitCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	comboBoxNew.SetCurSel(0);  // set default value of ComboBox comboBoxNew to “Left” which has index 0

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSinanBitCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSinanBitCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSinanBitCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





// YOUR CODE STARTS FROM HERE

bool operand1Entered = false;
bool operand2Entered = false;
bool andselected = true;
bool orselected = false;
bool xorselected = false;
int maxSize = 0;


void CSinanBitCalculatorDlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	andselected = true;
	orselected = false;
	xorselected = false;
	UpdateData(TRUE);
}


void CSinanBitCalculatorDlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	orselected = true;
	andselected = false;
	xorselected = false;
	UpdateData(TRUE);
}


void CSinanBitCalculatorDlg::OnBnClickedRadio3()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	xorselected = true;
	andselected = false;
	orselected = false;
	UpdateData(TRUE);
}


void CSinanBitCalculatorDlg::OnBnClickedCheck1()
{
	// TODO: Add your control notification handler code here
	if (checkVariable.GetCheck()) 
	{ // Enable the MFC object, so that the user can interact with it 
		comboBoxNew.EnableWindow(TRUE);
		bitshiftingvariable.EnableWindow(TRUE);
	} 
	else 
	{ // Disable the MFC Object 
		comboBoxNew.EnableWindow(FALSE);
		bitshiftingvariable.EnableWindow(FALSE);
	}
}


void CSinanBitCalculatorDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	CString number1, number2, bitcontent, finalValue, message;
	unsigned int myUnsignedInt1, myUnsignedInt2;
	int resultInt;

	bitshiftingvariable.GetWindowTextW(bitcontent);

	CDC *pDC = GetDC();// This class is necessary to get the length of the string 
	CSize cz;// An object which keeps the length of the string.

	input1.GetWindowTextW (number1);  // number = inputBox1 (both of them cstring)
	myUnsignedInt1 = _tcstoul(number1, nullptr, 10);  // cstring to unsigned int

	input2.GetWindowTextW (number2);  // number = inputBox1 (both of them cstring)
	myUnsignedInt2 = _tcstoul(number2, nullptr, 10);  // cstring to unsigned int

//input checks
	if (number1 == "" || number2 == "")
		message = "At least one operand was not entered.";
//		listVariable.AddString(_T("At least one operand was not entered."));

	else if (checkVariable.GetCheck() != 0 && bitcontent == "")
		message = "Specify how many bits you want to shift";
//		listVariable.AddString(_T("Specify how many bits you want to shift"));

	else
	{  //actual program starts 
		if (andselected)  // AND (&)
		{
			resultInt = myUnsignedInt1 & myUnsignedInt2;
		}

		else if (orselected)  // OR  (|)
		{
			resultInt = myUnsignedInt1 | myUnsignedInt2;
		}

		else if (xorselected)  // XOR  (^)
		{
			resultInt = myUnsignedInt1 ^ myUnsignedInt2;
		}

		if (checkVariable.GetCheck() != 0)  // shifting
		{
			CString content;
			int repeat = _ttoi(bitcontent);
			comboBoxNew.GetWindowTextW(content);

			if (content == "Left")
			{
				for (int i=0; i<repeat; i++)
					resultInt = resultInt << 1;  // left shifting
			}

			else if (content == "Right")
			{
				for (int i=0; i<repeat; i++)
					resultInt = resultInt >> 1;  // right shifting
			}
		}

		// message that will display

		if (andselected)  // AND (&)
		{
			finalValue.Format(_T("%d"), resultInt);
			message = number1 + _T(" AND ")+ number2 + _T(" = ") + finalValue;
		}

		else if (orselected)  // OR  (|)
		{
			finalValue.Format(_T("%d"), resultInt);
			message = number1 + _T(" OR ")+ number2 + _T(" = ") + finalValue;
		}

		else if (xorselected)  // XOR  (^)
		{
			finalValue.Format(_T("%d"), resultInt);
			message = number1 + _T(" XOR ")+ number2 + _T(" = ") + finalValue;
		}
}
		listVariable.AddString(message);

		input1.SetWindowTextW (_T(""));
		input2.SetWindowTextW (_T(""));

		cz = pDC->GetTextExtent(message);// Returns the size of the string to cz object 
		if(cz.cx > maxSize)// cz.cx keeps the horizontal length of the string. We compare 
			maxSize = cz.cx; // it with maxSize and update the maxSize if the condition // is satisfied
		listVariable.SetHorizontalExtent(maxSize);// Set the Horizontal scrollbar length to maxSize
	
}


void CSinanBitCalculatorDlg::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
}


void CSinanBitCalculatorDlg::OnEnChangeEdit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CSinanBitCalculatorDlg::OnLbnSelchangeList1()
{
	// TODO: Add your control notification handler code here
}
