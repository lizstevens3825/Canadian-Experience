/**
 * \file TimelineDlg.h
 *
 * \author Elizabeth Stevens
 *
 * Dialog box for our Timeline values
 */

#pragma once

class CTimeline;

/** CTimelineDlg dialog 
 *
 * Dialog box for our Timeline values
 */
class CTimelineDlg : public CDialog
{
	DECLARE_DYNAMIC(CTimelineDlg)

public:
	/** Constructor
	* \param pParent */
	CTimelineDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CTimelineDlg();
	void SetTimeline(CTimeline* timeline);
	void Take();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TIMELINEDLG };
#endif

protected:
	/** Only commented for doxygen
	* \param pDX */
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	/// The number of frames
	int mNumFrames;

	/// The frame rate
	int mFrameRate;

	/// The timeline we are editing
	CTimeline* mTimeline = nullptr;
};
