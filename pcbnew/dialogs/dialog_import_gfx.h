/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2013 Jean-Pierre Charras, jp.charras at wanadoo.fr
 * Copyright (C) 1992-2016 KiCad Developers, see AUTHORS.txt for contributors.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you may find one here:
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 * or you may search the http://www.gnu.org website for the version 2 license,
 * or you may write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

#include <dialog_import_gfx_base.h>
#include <import_gfx/graphics_importer_pcbnew.h>

class PCB_BASE_FRAME;

class DIALOG_IMPORT_GFX : public DIALOG_IMPORT_GFX_BASE
{
public:
    DIALOG_IMPORT_GFX( PCB_BASE_FRAME* aParent, bool aUseModuleItems = false );
    ~DIALOG_IMPORT_GFX();

    /**
     * Function GetImportedItems()
     *
     * Returns a list of items imported from a vector graphics file.
     */
    std::list<std::unique_ptr<EDA_ITEM>>& GetImportedItems()
    {
        return m_importer->GetItems();
    }

private:
    PCB_BASE_FRAME*      m_parent;
    wxConfigBase*        m_config;               // Current config
    std::unique_ptr<GRAPHICS_IMPORTER_PCBNEW> m_importer;
    int                  m_gridUnits;
    double               m_gridOffsetX;
    double               m_gridOffsetY;

    static wxString      m_filename;
    static int           m_offsetSelection;
    static LAYER_NUM     m_layer;

    // Virtual event handlers
    void OnCancelClick( wxCommandEvent& event ) override { event.Skip(); }
    void OnOKClick( wxCommandEvent& event ) override;
    void OnBrowseFiles( wxCommandEvent& event ) override;
    void OriginOptionOnUpdateUI( wxUpdateUIEvent& event ) override;
    int  GetPCBGridUnits( void );
    void GetPCBGridOffsets( double &aXOffset, double &aYOffset );
};
